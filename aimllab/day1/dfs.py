import matplotlib.pyplot as plt
import networkx as nx

JUG1_CAPACITY = 4
JUG2_CAPACITY = 3
GOAL = 2

def get_successors(state):
    a, b = state
    pour1 = min(a, JUG2_CAPACITY - b)
    pour2 = min(b, JUG1_CAPACITY - a)
    successors = set([
        (JUG1_CAPACITY, b),
        (a, JUG2_CAPACITY),
        (0, b),
        (a, 0),
        (a - pour1, b + pour1),
        (a + pour2, b - pour2),
    ])

    return successors

def assign_pos(G, node, pos, depth=0, x=0):
    if node not in pos:
        pos[node] = (x, -depth)
        children = list(G.successors(node))
        if children:
            start_x = x - len(children)
            for i, child in enumerate(children):
                assign_pos(G, child, pos, depth + 1, start_x + i * 4)

def dfs(start):
    G = nx.DiGraph()
    G.add_node(start)
    visited = set([start])
    stack = [start]
    pos = {}

    print("Visited:", start)
    while stack:
        current = stack.pop()

        if current[0] == GOAL or current[1] == GOAL:
            print("Goal reached:", current)
            break

        for succ in get_successors(current):
            if succ not in visited:
                visited.add(succ)
                print("Visited:", succ)
                G.add_edge(current, succ)
                stack.append(succ)

    assign_pos(G, start, pos)
    colors = ["orange" if node == current else "lightblue" for node in G.nodes]
    nx.draw(G, pos, with_labels=True, node_color=colors, node_size=800)
    plt.show()

dfs((0, 0))
