import tkinter as tk
from tkinter import ttk
import matplotlib.pyplot as plt
import networkx as nx
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import math

# --- Graph / state ---
G = nx.DiGraph()
pos, node_values, levels = {}, {}, {}
root_num, winner_var = (7,), None
pruned_edges = set()     # actually-applied prunes (updated during stepping)
trace_paths = []         # list of path-action lists (one path per step)
step_index = 0


# --- Helpers to build tree ---
def factors(num):
    return [(lo, num - lo) for lo in range(1, num) if lo < num - lo]


def make_child(parent, comp, fact):
    lst = list(parent)
    lst.remove(comp)
    lst.extend(fact)
    return tuple(sorted(lst, reverse=True))


def prepare_expansions(start):
    visited, queue, steps = {start: 0}, [(start, 0)], []
    while queue:
        parent, depth = queue.pop(0)
        for comp in parent:
            for fact in factors(comp):
                child = make_child(parent, comp, fact)
                if child not in visited:
                    visited[child] = depth + 1
                    queue.append((child, depth + 1))
                if visited[child] == depth + 1:
                    steps.append((parent, child, depth + 1))
    return steps, visited


def compute_positions(levels_map):
    pos_local, max_depth = {}, max(levels_map.values(), default=0)
    for d in range(max_depth + 1):
        nodes = sorted([n for n, lv in levels_map.items() if lv == d])
        for i, node in enumerate(nodes):
            pos_local[node] = ((i + 1) / (len(nodes) + 1), -d)
    return pos_local


# --- Alpha-beta traversal generator (yields one full root->leaf path result per yield)
# Note: generator yields a list of actions representing one "path evaluation" (visit/update/assign/prune)
# It does NOT modify pruned_edges; it only returns actions. pruned_edges is applied later during stepping.
def alpha_beta_trace(node, depth, alpha, beta, maximizing_player):
    path_actions = []

    # Leaf node: evaluate and return a single path containing visit+assign
    if not list(G.successors(node)):
        val = 1 if levels[node] % 2 == 0 else -1
        path_actions.append(("visit", node, alpha, beta, val))
        path_actions.append(("assign", node, val))
        yield path_actions
        return val

    # start with a visit action for this internal node
    value = float("-inf") if maximizing_player else float("inf")
    path_actions.append(("visit", node, alpha, beta, value))

    succs = list(G.successors(node))
    for i, child in enumerate(succs):
        # Evaluate child's path(s); use `yield from` so child yields appear as separate path yields,
        # and child_val receives the child's returned numeric value.
        child_val = yield from alpha_beta_trace(child, depth + 1, alpha, beta, not maximizing_player)

        # update this node's value/alpha/beta based on child's returned numeric result
        if maximizing_player:
            value = max(value, child_val)
            alpha = max(alpha, value)
        else:
            value = min(value, child_val)
            beta = min(beta, value)

        path_actions.append(("update", node, alpha, beta, value))

        # If pruning condition met, append prune actions for the *remaining* children
        if alpha >= beta:
            for sibling in succs[i + 1:]:
                path_actions.append(("prune", (node, sibling)))
            break

    # assign final best value for this node
    path_actions.append(("assign", node, value))
    yield path_actions
    return value


# --- Drawing utility ---
def draw_graph(highlight_nodes=None, alpha_beta_map=None):
    ax.clear()
    labels, colors = {}, []

    if highlight_nodes is None:
        highlight_nodes = []
    if alpha_beta_map is None:
        alpha_beta_map = {}

    # Node coloring and labels
    for n in G.nodes():
        val = node_values.get(n)
        if n in highlight_nodes:
            colors.append("yellow")
        elif val == 1:
            colors.append("lightgreen")
        elif val == -1:
            colors.append("lightcoral")
        else:
            colors.append("lightblue")

        if n in alpha_beta_map:
            a, b, v = alpha_beta_map[n]
            # format numbers but allow inf/-inf
            def fmt(x):
                if x == float("inf"):
                    return "inf"
                if x == float("-inf"):
                    return "-inf"
                # avoid NaN
                if x is None or (isinstance(x, float) and math.isnan(x)):
                    return ""
                return f"{x:.1f}"
            labels[n] = f"{'+'.join(map(str, n))}\nα={fmt(a)}, β={fmt(b)}, v={fmt(v)}"
        else:
            labels[n] = f"{'+'.join(map(str, n))}\n{val if val is not None else ''}"

    explored_edges = [(u, v) for u, v in G.edges() if (u, v) not in pruned_edges]
    nx.draw_networkx_nodes(G, pos, ax=ax, node_color=colors, node_size=1400)
    nx.draw_networkx_edges(G, pos, ax=ax, edgelist=explored_edges, edge_color="black")
    if pruned_edges:
        nx.draw_networkx_edges(G, pos, ax=ax, edgelist=list(pruned_edges),
                               edge_color="gray", style="dashed")
    nx.draw_networkx_labels(G, pos, ax=ax, labels=labels, font_size=8)

    # Min/Max labels at left
    for d in range(max(levels.values(), default=0) + 1):
        ax.text(-0.1, -d, "Min" if d % 2 == 0 else "Max",
                fontsize=10, ha="right", va="center", fontweight="bold")

    ax.set_axis_off()
    ax.set_xlim(-0.2, 1.05)
    canvas.draw()


# --- Stepper: apply one path's actions at a time ---
def step():
    global step_index
    if step_index < len(trace_paths):
        actions = trace_paths[step_index]
        step_index += 1

        highlight_nodes = []
        alpha_beta_map = {}

        # Apply all actions in the path at once (update mapping, apply assigns and prunes)
        for act in actions:
            if act[0] == "visit":
                _, node, a, b, v = act
                highlight_nodes.append(node)
                alpha_beta_map[node] = (a, b, v)

            elif act[0] == "update":
                _, node, a, b, v = act
                alpha_beta_map[node] = (a, b, v)

            elif act[0] == "assign":
                _, node, v = act
                node_values[node] = v
                # ensure label shows final v; keep previous a/b if present
                if node in alpha_beta_map:
                    a, b, _ = alpha_beta_map[node]
                    alpha_beta_map[node] = (a, b, v)
                else:
                    alpha_beta_map[node] = (float("-inf"), float("inf"), v)

            elif act[0] == "prune":
                _, edge = act
                pruned_edges.add(edge)

        # draw the entire path as a single update
        draw_graph(highlight_nodes, alpha_beta_map)

    else:
        # finished all paths
        root_val = node_values.get(root_num)
        winner_var.set(
            "Result: Min wins" if root_val == 1 else
            "Result: Max wins" if root_val == -1 else ""
        )
        draw_graph()


# --- UI setup ---
root = tk.Tk()
root.title("Alpha-Beta Pruning Visualization (Path Mode)")

frame = ttk.Frame(root)
frame.pack(side=tk.TOP, fill=tk.BOTH, expand=True)
fig, ax = plt.subplots(figsize=(10, 6))
canvas = FigureCanvasTkAgg(fig, master=frame)
canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)

ttk.Button(frame, text="Step", command=step).pack(side=tk.LEFT, padx=5, pady=6)
ttk.Button(frame, text="Reset", command=lambda: reset()).pack(side=tk.LEFT, padx=5, pady=6)
winner_var = tk.StringVar()
ttk.Label(root, textvariable=winner_var, font=("Arial", 12, "bold")).pack(side=tk.BOTTOM, pady=6)


# --- Reset helper ---
def reset():
    global pruned_edges, node_values, trace_paths, step_index
    pruned_edges = set()
    node_values = {}
    step_index = 0
    # recompute trace_paths fresh (they don't modify global pruned_edges)
    trace_paths = list(alpha_beta_trace(root_num, 0, float("-inf"), float("inf"), True))
    draw_graph()


# --- Build full tree once at startup ---
expansion_steps, levels = prepare_expansions(root_num)
G.add_node(root_num)
for p, c, _ in expansion_steps:
    G.add_node(c)
    G.add_edge(p, c)

pos = compute_positions(levels)

# prepare trace paths (generation does not apply prunes globally)
trace_paths = list(alpha_beta_trace(root_num, 0, float("-inf"), float("inf"), True))

# initial draw
draw_graph()

root.mainloop()
