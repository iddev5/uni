import random

data = [
    (2, 6),
    (3, 4),
    (3, 8),
    (4, 7),
    (6, 2),
    (6, 4),
    (7, 3),
    (7, 4),
    (8, 5),
    (7, 6)
]

k = 2
max_iter = 10

def manhattan_distance(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

def initialize_medoids(data, k):
    # return random.sample(data, k)
    return ((3, 4), (7, 4))

def assign_points(data, medoids):
    clusters = {medoid: [] for medoid in medoids}
    for point in data:
        distances = [manhattan_distance(point, medoid) for medoid in medoids]
        min_index = distances.index(min(distances))
        clusters[medoids[min_index]].append(point)
    return clusters

def update_medoids(clusters):
    new_medoids = []
    for medoid, points in clusters.items():
        if not points:
            continue
        total_distances = []
        for candidate in points:
            total_distance = sum(manhattan_distance(candidate, p) for p in points)
            total_distances.append((total_distance, candidate))
        total_distances.sort()
        new_medoids.append(total_distances[0][1])

    return new_medoids

medoids = initialize_medoids(data, k)
print("Initial medoids:", medoids)

for iteration in range(max_iter):
    clusters = assign_points(data, medoids)
    
    print(f"\nIteration {iteration+1}:")
    print("Medoids:", medoids)
    for medoid, points in clusters.items():
        print(f"Cluster for medoid {medoid}: {points}")

    new_medoids = update_medoids(clusters)
    
    if set(new_medoids) == set(medoids):
        print("\nConverged!")
        break
    medoids = new_medoids

# print("\nFinal Medoids:", medoids)
# print("Final Clusters:")
# for medoid, points in clusters.items():
#     print(f"Medoid {medoid}: {points}")