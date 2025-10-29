import matplotlib.pyplot as plt
import networkx as nx

nodes = {
    1: "1: E(S(A,B,C), 180°)",
    2: "2: E(S(e(C), C), 180°)",
    3: "3: ¬E(x,y) ∨ ¬E(y,z) ∨ E(x,z)",
    4: "4: ¬E(S(x,y), S(x,z)) ∨ E(y,z)",
    5: "5: ¬E(S(x,y), S(x,z)) ∨ E(y,z)",
    6: "6: ¬E(e(C), S(A,B))  (Negated Goal)",
    7: "7: E(S(e(C), C), S(A,B,C))",
    8: "8: E(S(A,B,C), S(A,B,C))",
    9: "9: E(S(e(C), S(A,B)), 180°)",
    10: "10: E(e(C), S(A,B))",
    11: "11: ⊘  (Proof Complete)"
}

edges = [
    (1, 7),
    (2, 7),
    (3, 9),
    (7, 9),
    (4, 9),
    (9, 10),
    (5, 10),
    (6, 11),
    (10, 11)
]

G = nx.DiGraph()
for nid, label in nodes.items():
    G.add_node(nid, label=label)

G.add_edges_from(edges)

pos = {
    1: (-5.0, 3.0),
    2: (-3.0, 3.0),
    3: (-6.0, 1.5),
    4: (-2.3, 1.7),
    5: (-0.3, 1.3),
    7: (-4.0, 1.8),
    8: (-4.0, 0.6),
    9: (-2.5, 0.4),
    10: (0.5, -0.3),
    6: (2.5, 1.5),
    11: (0.5, -1.6)
}

plt.figure(figsize=(12, 8))
nx.draw_networkx_nodes(G, pos, node_size=3000, node_color="lightblue", edgecolors="black", linewidths=1.0)
nx.draw_networkx_edges(G, pos, arrowstyle="->", arrowsize=18, width=2.0, edge_color="gray")
labels = nx.get_node_attributes(G, 'label')
nx.draw_networkx_labels(G, pos, labels, font_size=9, font_weight='bold')
plt.title("Resolution Proof Tree for Exterior Angle Theorem", fontsize=14, fontweight='bold')
plt.axis('off')
plt.tight_layout()
plt.show()
