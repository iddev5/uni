import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import networkx as nx

# =======================
# Config (edit as needed)
# =======================
CAP_A, CAP_B = 4, 3              # jug capacities
START = (0, 0)                   # start state
GOAL_AMOUNT = 2                  # goal: amount in jug A == GOAL_AMOUNT
MAX_DEPTH = 20                   # safety cap

# Move generator (deterministic order)
def next_states(s):
    a, b = s
    moves = []
    # Fill A, Fill B
    moves.append((CAP_A, b))
    moves.append((a, CAP_B))
    # Empty A, Empty B
    moves.append((0, b))
    moves.append((a, 0))
    # Pour A -> B
    pour = min(a, CAP_B - b)
    moves.append((a - pour, b + pour))
    # Pour B -> A
    pour = min(b, CAP_A - a)
    moves.append((a + pour, b - pour))
    # Filter self-loops
    out = []
    seen_local = set()
    for ns in moves:
        if ns != s and ns not in seen_local:
            seen_local.add(ns)
            out.append(ns)
    return out

# ================
# IDDFS + logging
# ================
discover_events = []  # [{node, parent, depth, limit}]
seen_global = set()
final_path = []

def iddfs(start):
    # First reveal: the root
    discover_events.append({"node": start, "parent": None, "depth": 0, "limit": 0})
    seen_global.add(start)

    def dls(u, limit, path, limit_tag):
        # Goal check
        if u[0] == GOAL_AMOUNT:
            final_path[:] = path[:]
            return True
        if limit == 0:
            return False
        # Depth-limited DFS
        for v in next_states(u):
            if v in path:        # avoid cycles on the current path
                continue
            if v not in seen_global:
                discover_events.append({
                    "node": v, "parent": u, "depth": len(path), "limit": limit_tag
                })
                seen_global.add(v)
            path.append(v)
            if dls(v, limit - 1, path, limit_tag):
                return True
            path.pop()
        return False

    # Iterative deepening
    for limit in range(MAX_DEPTH + 1):
        if dls(start, limit, [start], limit):
            break

iddfs(START)

# ==========================
# Build frames for animation
# ==========================
# Final path edges for highlighting
final_edges = set()
for i in range(len(final_path) - 1):
    final_edges.add((final_path[i], final_path[i + 1]))

# 1 frame per discovery + 1 final highlight frame
TOTAL_FRAMES = len(discover_events) + 1

# =======================
# Tree layout (dynamic)
# =======================
def make_partial_tree(events_upto):
    """Build adjacency of the search tree from the first k discovery events."""
    adj = {}
    nodes = set()
    for ev in events_upto:
        n, p = ev["node"], ev["parent"]
        nodes.add(n)
        if p is not None:
            nodes.add(p)
            adj.setdefault(p, []).append(n)
        else:
            adj.setdefault(n, [])
    # Ensure all nodes present as keys
    for n in list(nodes):
        adj.setdefault(n, [])
    return adj

def assign_positions(adj, root):
    """Reingold–Tilford-like layout: separate horizontal span per subtree; parent centered."""
    pos = {}
    x_cursor = [0.0]  # mutable holder so inner function can advance

    def dfs_place(node, depth):
        children = adj.get(node, [])
        if not children:
            pos[node] = (x_cursor[0], -depth)
            x_cursor[0] += 1.0
        else:
            xs = []
            for ch in children:
                dfs_place(ch, depth + 1)
                xs.append(pos[ch][0])
            pos[node] = (sum(xs) / len(xs), -depth)

    dfs_place(root, 0)
    return pos

# =======================
# Animation
# =======================
fig, ax = plt.subplots(figsize=(9, 6))

def update(frame):
    ax.clear()
    ax.axis('off')

    if frame < len(discover_events):
        events_now = discover_events[: frame + 1]
        current = discover_events[frame]["node"]
        limit = discover_events[frame]["limit"]
        title = f"Step {frame+1}/{len(discover_events)}  |  Reveal {current}  |  Depth limit = {limit}"
    else:
        events_now = discover_events
        current = None
        title = f"Goal reached: {' → '.join(map(str, final_path))}"

    adj = make_partial_tree(events_now)
    G = nx.DiGraph()
    for p, children in adj.items():
        for c in children:
            G.add_edge(p, c)

    # Layout for current partial tree
    pos = assign_positions(adj, START)

    # Node styling
    nodes_now = list(G.nodes())
    depths = {ev["node"]: ev["depth"] for ev in events_now}
    labels = {n: f"{n}\nd={depths.get(n, 0)}" for n in nodes_now}

    # Colors: latest = red, others = lightblue; final frame → final path = green
    colors = []
    if frame < len(discover_events):
        for n in nodes_now:
            colors.append("red" if n == current else "lightblue")
    else:
        for n in nodes_now:
            colors.append("green" if n in final_path else "lightblue")

    # Draw base tree
    nx.draw_networkx_edges(G, pos, width=2.0, arrows=False, alpha=0.6, ax=ax)
    nx.draw_networkx_nodes(G, pos, nodelist=nodes_now, node_color=colors, node_size=1200, ax=ax)
    nx.draw_networkx_labels(G, pos, labels=labels, font_size=10, ax=ax)

    # Final path overlay thicker
    if frame == len(discover_events) and final_edges:
        nx.draw_networkx_edges(G, pos, edgelist=list(final_edges), width=4.0, arrows=False, ax=ax)

    ax.set_title(title)

ani = FuncAnimation(fig, update, frames=TOTAL_FRAMES, interval=900, repeat=False)
plt.tight_layout()
plt.show()

# Console summary
print("Final path:", " -> ".join(map(str, final_path)))
print("Depth (distance from root) of revealed nodes:")
seen_depth = {ev["node"]: ev["depth"] for ev in discover_events}
for n, d in sorted(seen_depth.items(), key=lambda x: (x[1], x[0])):
    print(f"  {n}: d={d}")