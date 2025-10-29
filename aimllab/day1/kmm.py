import random

k = 3
max_iters = 10
D = [3, 5, 2, 7, 12, 14, 6, 4, 19, 17]

def kmm(D, k, centroids=None):
    if centroids is None:
        centroids = []
        while len(centroids) == 0 or (len(set(centroids)) != len(centroids)):
            centroids = []
            for _ in range(k):
                centroids.append(D[random.randint(0, len(D) - 1)])

    for i, c in enumerate(centroids):
        print(f"Initial centroid of cluster {i + 1}: {c}")

    prev_sum = [0 for _ in range(k)]
    clusters = [[] for _ in range(k)]

    for i in range(max_iters):
        curr_sum = [0 for _ in range(k)]
        clusters = [[] for _ in range(k)]

        for n in D:
            val = None
            min_ic = None

            for ic, cent in enumerate(centroids):
                dist = abs(cent - n) # Manhattan distance
                if val is None or dist < val:
                    val = dist
                    min_ic = ic

                # Sum of distances
                curr_sum[ic] += dist

            if min_ic is not None:
                clusters[min_ic].append(n)

        sum_diff_count = 0

        for i in range(k):
            if curr_sum[i] != prev_sum[i]:
                sum_diff_count += 1

        if sum_diff_count == 0:
            print("\nPrevious sum of distances and current one is equal. So our clusters are correct")
            return clusters
        
        print("\nPrevious sum of distances and current one is unequal. So recalculate centroids")

        for i, c in enumerate(clusters):
            mean = sum(c) / len(c)
            centroids[i] = mean
            prev_sum = curr_sum
            print(f"New centroid of cluster {i + 1}: {mean}")

    return clusters

print(f"\nFinal clusters are: {kmm(D, k)}")