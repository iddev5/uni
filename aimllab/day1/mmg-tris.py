import matplotlib.pyplot as plt
import networkx as nx
from collections import defaultdict

def unequal_splits(n):
    splits = []
    for small in range(1, n // 2 + 1):
        big = n - small
        if big != small:
            splits.append((big, small))
    return splits

def build(start_pile):
    G = nx.DiGraph()
    start_state = tuple(sorted([start_pile], reverse=True))
    G.add_node(start_state)

    def recurse(state):
        for i, pile in enumerate(state):
            if pile > 2:
                for big, small in unequal_splits(pile):
                    new_state = list(state[:i] + state[i+1:])
                    new_state.extend([big, small])
                    new_state = tuple(sorted(new_state, reverse=True))
                    if new_state not in G: 
                        G.add_node(new_state)
                        recurse(new_state)
                    G.add_edge(state, new_state, move=f"{pile} → {big}+{small}")
            elif pile == 3:
                big, small = 2, 1
                new_state = list(state[:i] + state[i+1:])
                new_state.extend([big, small])
                new_state = tuple(sorted(new_state, reverse=True))
                if new_state not in G:
                    G.add_node(new_state)
                    recurse(new_state)
                G.add_edge(state, new_state, move=f"{pile} → {big}+{small}")

    recurse(start_state)
    return G

def hierarchical_layout(G, root):
    levels = defaultdict(list)
    visited = set()
    queue = [(root, 0)]
    while queue:
        node, depth = queue.pop(0)
        if node in visited:
            continue
        visited.add(node)
        levels[depth].append(node)
        for child in G.successors(node):
            queue.append((child, depth + 1))
    pos = {}
    max_width = max(len(nodes) for nodes in levels.values())
    for depth, nodes in levels.items():
        dx = 1.0 / (len(nodes) + 1)
        for i, node in enumerate(nodes):
            pos[node] = (i * dx + dx, -depth)
    return pos

def visualize_stick(start_pile, figsize=(14, 10)):
    G = build(start_pile)
    root = tuple([start_pile])
    node_labels = {n: "+".join(map(str, n)) for n in G.nodes}
    edge_labels = {(u, v): d["move"] for u, v, d in G.edges(data=True)}

    pos = hierarchical_layout(G, root)

    plt.figure(figsize=figsize)
    nx.draw_networkx_nodes(G, pos, node_size=2000, node_color="#cfe9ff", edgecolors="#2b6ea3")
    nx.draw_networkx_labels(G, pos, labels=node_labels, font_size=11, font_weight="bold")
    nx.draw_networkx_edges(G, pos, arrows=True, arrowstyle="-|>", arrowsize=12, width=1.0)
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=9.5, label_pos=0.4)

    plt.title(f"Min_Max stick game — start: {start_pile}", fontsize=14)
    plt.axis("off")
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    visualize_stick(7)
