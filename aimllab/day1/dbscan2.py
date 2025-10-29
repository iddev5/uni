from math import sqrt

d = 1.9
n = 4

X = [
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
]

def euclidean_distance(p1, p2):
    return sqrt( ((p1[0] - p2[0]) ** 2) + ((p1[1] - p2[1]) ** 2) )

def dbscan():
    table = {}
    for i, pt in enumerate(X):
        table[i] = {}
        for oi in range(i+1):
            dist = euclidean_distance(pt, X[oi])
            table[i][oi] = dist
    return table

table = dbscan()

print("    ", end="")
[print(f"P{i+1:3} ", end="") for i in range(len(X))]
print()
for k, v in table.items():
    print(f"P{k+1:2} ", end="")
    for dist in v.values():
        print(f"{dist:.2f} ", end="")
    print()

clusters = {}
for k, v in table.items():
    clusters[k] = set()
    for dk, dist in v.items():
        if dist < d:
            clusters[k].add(dk)

    for i in range(k, len(X)):
        dist = table[i][k]
        if dist < d:
            clusters[k].add(i)

print()
for k, cluster in clusters.items():
    print(f"P{k+1}\t", "Noise" if len(cluster) < n else "Core", "\t", "Border" if len(cluster) < n else "Centre", end="\t")
    print(cluster)
