import matplotlib.pyplot as plt
import networkx as nx

JUG1_CAPACITY = 4
JUG2_CAPACITY = 3
GOAL = 2
DEPTH_CUTOFF = 5

def assign_pos(G, node, pos, depth=0, x=0):
    if node not in pos:
        pos[node] = (x, -depth)
        children = list(G.successors(node))
        if children:
            start_x = x - len(children)
            for i, child in enumerate(children):
                assign_pos(G, child, pos, depth + 1, start_x + i * 4)

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

def idfs(start, depth_cutoff=1):
    G = nx.DiGraph()
    G.add_node(start)

    depth = 1
    print("Starting at depth", depth_cutoff)
    stack = [start]
    visited = set([start])
    print("Visited:", start)
    pos = {}
    elem = None

    while stack and depth <= depth_cutoff:
        elem = stack.pop()

        if elem[0] == GOAL or elem[1] == GOAL:
            print("Goal reached:", elem)
            return True
        
        for succ in get_successors(elem):
            if succ not in visited:
                visited.add(succ)
                stack.append(succ)
                G.add_edge(elem, succ)
                print("Visited:", succ)

        depth += 1

    assign_pos(G, start, pos)
    colors = ["orange" if node == elem else "lightblue" for node in G.nodes]
    nx.draw(G, pos, with_labels=True, node_color=colors, node_size=800)
    plt.show()

    return idfs(start, depth_cutoff+1)

idfs((0, 0))