import matplotlib.pyplot as plt
import networkx as nx
from collections import deque

JUG1_CAPACITY = 4
JUG2_CAPACITY = 3
GOAL = 2

def get_successors(state):
    successors = set()
    a, b = state

    successors.add((JUG1_CAPACITY, b))
    successors.add((a, JUG2_CAPACITY))
    successors.add((0, b))
    successors.add((a, 0))
    pour = min(a, JUG2_CAPACITY - b)
    successors.add((a - pour, b + pour))
    pour = min(b, JUG1_CAPACITY - a)
    successors.add((a + pour, b - pour))

    return successors

def assign_pos(G, node, pos, depth=0, x=0):
    if node not in pos:
        pos[node] = (x, -depth)
        children = list(G.successors(node))
        if children:
            start_x = x - len(children) / 2
            for i, child in enumerate(children):
                assign_pos(G, child, pos, depth + 1, start_x + i * 2)

def bfs(start):
    G = nx.DiGraph()
    G.add_node(start)
    visited = set()
    visited.add(start)
    parent = {}
    parent[start] = None
    queue = deque([start])
    pos = {}

    print("Visited:", start)
    while queue:
        current = queue.popleft()

        if current[0] == GOAL or current[1] == GOAL:
            print("Goal reached:", current)
            break

        for succ in get_successors(current):
            if succ not in visited:
                visited.add(succ)
                print("Visited:", succ)
                parent[succ] = current
                G.add_edge(current, succ)
                queue.append(succ)

    assign_pos(G, start, pos)
    fig, ax = plt.subplots(figsize=(10, 6))
    colors = ["orange" if node == current else "lightblue" for node in G.nodes]
    nx.draw(G, pos, with_labels=True, node_color=colors, node_size=800, ax=ax)
    plt.show()

start_state = (0, 0)
bfs(start_state)
