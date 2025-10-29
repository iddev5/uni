import numpy as np
import math
import matplotlib.pyplot as plt
import networkx as nx

def euclidean_distance(p1, p2):
    return np.sqrt(np.sum((p1 - p2) ** 2))

def get_neighbors(X, point_idx, eps):
    neighbors = []
    for i in range(len(X)):
        if euclidean_distance(X[point_idx], X[i]) <= eps:
            neighbors.append(i)
    return neighbors

def dbscan(X, eps, min_samples):
    labels = [-1] * len(X)  # -1 = Unclassified/noise
    cluster_id = 0

    for i in range(len(X)):
        if labels[i] != -1:
            continue
        
        neighbors = get_neighbors(X, i, eps)

        if len(neighbors) < min_samples:
            labels[i] = -1
        else:
            labels[i] = cluster_id
            k = 0
            while k < len(neighbors):
                point = neighbors[k]

                if labels[point] == -1:
                    labels[point] = cluster_id

                if labels[point] != -1:
                    k += 1
                    continue

                labels[point] = cluster_id
                point_neighbors = get_neighbors(X, point, eps)

                if len(point_neighbors) >= min_samples:
                    neighbors += point_neighbors

                k += 1

            cluster_id += 1

    return labels

X = np.array([
    [3, 7],
    [4, 6],
    [5, 5],
    [6, 4],
    [7, 3],
    [6, 2],
    [7, 2],
    [8, 4],
    [3, 3],
    [2, 6],
    [3, 5],
    [2, 4]
])

eps = 1.9
min_samples = 4

labels = dbscan(X, eps, min_samples)
print("Cluster Labels:", labels)

G = nx.Graph()

# Add nodes with cluster labels
for i, point in enumerate(X):
    G.add_node(i, pos=(point[0], point[1]), cluster=labels[i])

# Add edges only between points in the same cluster (ignore noise)
for i in range(len(X)):
    for j in range(i + 1, len(X)):
        if labels[i] != -1 and labels[i] == labels[j]:
            G.add_edge(i, j)

# Extract positions for visualization
pos = nx.get_node_attributes(G, 'pos')

# Color nodes by cluster label
node_colors = []
for i in G.nodes():
    if labels[i] == -1:
        node_colors.append("black")  # Noise
    else:
        node_colors.append(f"C{labels[i]}")  # Cluster color

plt.figure(figsize=(8, 6))
nx.draw(
    G, pos,
    with_labels=True,
    node_color=node_colors,
    node_size=500,
    font_size=8,
    edge_color="gray"
)

plt.title("DBSCAN Clustering as Graph (NetworkX)")
plt.show()
