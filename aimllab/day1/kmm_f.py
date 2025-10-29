
k = 2
D = [3, 5, 2, 7, 12, 14, 6, 4, 19, 17]

clusters = []

clusters = [[7], [12]]

# for i in range(k):
#     clusters.append([D[i]])

for n in D:
    val = 10E10
    min_c = None
    for c in clusters:
        this_c_val = abs(c[0] - n)
        if this_c_val < val:
            val = this_c_val
            min_c = c
    if min_c is not None and n != min_c[0]:
        min_c.append(n)

for i, c in enumerate(clusters):
    mean = sum(c) / len(c)
    print(f"Mean of cluster {i + 1}: {mean}")

print(clusters)