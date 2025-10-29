import tkinter as tk
from tkinter import ttk
import matplotlib.pyplot as plt
import networkx as nx
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

# --- Globals ---
G = nx.DiGraph()
pos, node_values, levels = {}, {}, {}
step_index, phase = 0, "evaluation"
root_num, winner_var = (7,), None
trace_paths = []   # stores evaluation traces (one path per step)
abv_values = {}    # node -> (alpha, beta, v)


# -------- Helper Functions ----------
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


# --------- Alpha-Beta Search with Tracing ----------
def alphabeta(node, depth, alpha, beta, maximizing, path):
    # Leaf
    if not list(G.successors(node)):
        val = 1 if depth % 2 == 0 else -1
        node_values[node] = val
        abv_values[node] = (alpha, beta, val)
        trace_paths.append(list(path + [(node, alpha, beta, val)]))
        return val

    v = float('-inf') if maximizing else float('inf')
    abv_values[node] = (alpha, beta, v)
    local_trace = path + [(node, alpha, beta, v)]

    for child in G.successors(node):
        val = alphabeta(child, depth + 1, alpha, beta, not maximizing, local_trace)
        if maximizing:
            v = max(v, val)
            alpha = max(alpha, v)
        else:
            v = min(v, val)
            beta = min(beta, v)

        abv_values[node] = (alpha, beta, v)
        trace_paths.append(list(path + [(node, alpha, beta, v), (child, alpha, beta, val)]))

        if beta <= alpha:  # prune
            break

    node_values[node] = v
    return v


# -------- GUI Drawing ----------
def draw_graph(highlight_path=None):
    ax.clear()
    labels, colors = {}, []
    for n in G.nodes():
        val = node_values.get(n)
        a, b, v = abv_values.get(n, ("", "", ""))
        if highlight_path and any(p[0] == n for p in highlight_path):
            colors.append("yellow")
        else:
            colors.append("lightgreen" if val == 1 else "lightcoral" if val == -1 else "lightblue")
        labels[n] = f"{'+'.join(map(str, n))}\nv={v}\nα={a}\nβ={b}"
    nx.draw_networkx(G, pos, ax=ax, arrows=False, node_color=colors, node_size=1600, labels=labels, font_size=7)

    for d in range(max(levels.values(), default=0) + 1):
        ax.text(-0.1, -d, "Min" if d % 2 == 0 else "Max",
                fontsize=10, ha="right", va="center", fontweight="bold")

    ax.set_axis_off()
    ax.set_xlim(-0.2, 1.05)
    canvas.draw()


# --------- Step Button Logic ----------
def step():
    global step_index
    if step_index < len(trace_paths):
        current_path = trace_paths[step_index]
        draw_graph(highlight_path=current_path)
        n, a, b, v = current_path[-1]
        winner_var.set(f"Step {step_index+1}: Node {n} → α={a}, β={b}, v={v}")
        step_index += 1
    else:
        root_val = node_values.get(root_num)
        winner_var.set("Result: Min wins" if root_val == 1 else "Result: Max wins" if root_val == -1 else "")


# --------- Setup ---------
root = tk.Tk()
root.title("Alpha-Beta Pruning Game")

frame = ttk.Frame(root)
frame.pack(side=tk.TOP, fill=tk.BOTH, expand=True)

fig, ax = plt.subplots(figsize=(10, 6))
canvas = FigureCanvasTkAgg(fig, master=frame)
canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)

ttk.Button(frame, text="Step", command=step).pack(side=tk.BOTTOM, padx=5)
winner_var = tk.StringVar()
ttk.Label(root, textvariable=winner_var, font=("Arial", 12, "bold")).pack(side=tk.BOTTOM, pady=6)

# Build tree fully at startup
expansion_steps, levels = prepare_expansions(root_num)
for p, c, _ in expansion_steps:
    G.add_node(c)
    G.add_edge(p, c)
pos = compute_positions(levels)

# Run alpha-beta once to generate traces
alphabeta(root_num, 0, float('-inf'), float('inf'), True, [])
draw_graph()

root.mainloop()
