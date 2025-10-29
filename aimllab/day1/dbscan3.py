from math import sqrt
import matplotlib.pyplot as plt
import networkx as nx

d, n = 1.9, 4
X = [[3,7],[4,6],[5,5],[6,4],[7,3],[6,2],[7,2],[8,4],[3,3],[2,6],[3,5],[2,4]]

def dist(p1, p2): return sqrt((p1[0]-p2[0])**2+(p1[1]-p2[1])**2)

def dbscan():
    table = {}
    for i, pt in enumerate(X):
        table[i] = {j: dist(pt, X[j]) for j in range(i+1)}
    return table

table = dbscan()

print("    ", end=""); [print(f"P{i+1:3} ", end="") for i in range(len(X))]; print()
for k, v in table.items():
    print(f"P{k+1:2} ", end=""); [print(f"{dval:.2f} ", end="") for dval in v.values()]; print()

clusters = {}
for k, v in table.items():
    c = {i for i in range(len(X)) if dist(X[k], X[i]) < d}
    clusters[k] = c

print()
for k, c in clusters.items():
    t = "Core" if len(c) >= n else "Noise"
    print(f"P{k+1}\t{t}\t", "Centre" if t=="Core" else "Border", c)

G = nx.Graph()
for i, (x, y) in enumerate(X): G.add_node(i, pos=(x, y))
for i in range(len(X)):
    for j in range(i+1, len(X)):
        if dist(X[i], X[j]) < d: G.add_edge(i, j)

pos = nx.get_node_attributes(G, 'pos')
colors = ["orange" if len(clusters[i]) >= n else "lightblue" for i in range(len(X))]

nx.draw(G, pos, with_labels=True,
        labels={i: f"P{i+1}" for i in range(len(X))},
        node_color=colors, node_size=600,
        font_size=10, edge_color="gray")

plt.title(f"DBSCAN Neighborhood Graph (d={d}, n={n})")
plt.show()
