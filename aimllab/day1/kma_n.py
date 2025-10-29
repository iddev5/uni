import matplotlib.pyplot as plt
import networkx as nx

data = [(2, 6), (3, 4), (3, 8), (4, 7), (6, 2), (6, 4), (7, 3), (7, 4), (8, 5), (7, 6)]
k = 2
max_iter = 10

manhattan_distance = lambda p1, p2: abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

def assign_points(data, medoids):
    clusters = {m: [] for m in medoids}
    for point in data:
        closest = min(medoids, key=lambda m: manhattan_distance(point, m))
        clusters[closest].append(point)
    return clusters

def update_medoids(clusters):
    new_medoids = []
    for points in clusters.values():
        new_medoid = min(points, key=lambda c: sum(manhattan_distance(c, p) for p in points))
        new_medoids.append(new_medoid)
    return new_medoids

medoids = [(3, 4), (7, 4)]
print("Initial Medoids:", medoids)

for iteration in range(max_iter):
    clusters = assign_points(data, medoids)
    print(f"\nIteration {iteration + 1}:")
    print("Medoids:", medoids)
    for medoid, points in clusters.items():
        print(f"Cluster for Medoid {medoid}: {points}")
    
    new_medoids = update_medoids(clusters)
    if set(new_medoids) == set(medoids):
        print("\nConverged!")
        break
    medoids = new_medoids

G = nx.Graph()
for idx, (medoid, points) in enumerate(clusters.items()):
    cluster_name = f"Cluster {idx+1}"
    for p in points:
        G.add_node(p, cluster=cluster_name, is_medoid=(p == medoid))
        if p != medoid:
            G.add_edge(medoid, p)

node_colors = ['red' if G.nodes[n]['is_medoid'] else 'lightblue' for n in G.nodes()]
node_sizes = [600 if G.nodes[n]['is_medoid'] else 300 for n in G.nodes()]
node_labels = {n: f"{n}\n{G.nodes[n]['cluster']}" for n in G.nodes()}

plt.figure(figsize=(8, 7))
pos = {node: node for node in G.nodes()}
nx.draw(G, pos, labels=node_labels, node_color=node_colors, node_size=node_sizes, 
        font_size=8, font_weight='bold')
plt.title("K-Medoids Clusters")
plt.show()