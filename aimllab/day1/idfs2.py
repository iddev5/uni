import matplotlib.pyplot as plt
import networkx as nx
import math

JUG1_CAPACITY = 4
JUG2_CAPACITY = 3
GOAL = 2

def get_successors(state):
    a, b = state
    pour1 = min(a, JUG2_CAPACITY - b)
    pour2 = min(b, JUG1_CAPACITY - a)
    successors = set([
        (JUG1_CAPACITY, b),       # Fill jug1
        (a, JUG2_CAPACITY),       # Fill jug2
        (0, b),                   # Empty jug1
        (a, 0),                   # Empty jug2
        (a - pour1, b + pour1),   # Pour jug1 -> jug2
        (a + pour2, b - pour2),   # Pour jug2 -> jug1
    ])
    return successors

def assign_pos(G, node, pos, depth=0, x=0):
    """Recursively assign positions for tree layout."""
    if node not in pos:
        pos[node] = (x, -depth)
        children = list(G.successors(node))
        if children:
            start_x = x - len(children)
            for i, child in enumerate(children):
                assign_pos(G, child, pos, depth + 1, start_x + i * 4)

def dls(node, depth_limit, G, visited, current_depth=0, path=None):
    """Depth-Limited Search building the graph, returns path to goal if found."""
    if path is None:
        path = [node]
    if current_depth >= depth_limit:
        return None
    for succ in get_successors(node):
        if succ not in visited:
            visited.add(succ)
            G.add_edge(node, succ)
            new_path = path + [succ]
            if succ[0] == GOAL or succ[1] == GOAL:
                return new_path
            found_path = dls(succ, depth_limit, G, visited, current_depth + 1, new_path)
            if found_path:
                return found_path
    return None

def iddfs(start, max_depth):
    cols = 3
    rows = math.ceil((max_depth + 1) / cols)
    plt.figure(figsize=(cols * 6, rows * 4))
    
    for depth in range(max_depth + 1):
        G = nx.DiGraph()
        G.add_node(start)
        visited = {start}
        found_path = dls(start, depth, G, visited)
        
        pos = {}
        assign_pos(G, start, pos)
        
        # Node colors: highlight path in orange
        node_colors = []
        edge_colors = []
        path_edges = set()
        if found_path:
            path_edges = {(found_path[i], found_path[i+1]) for i in range(len(found_path)-1)}
        
        for node in G.nodes:
            if found_path and node in found_path:
                node_colors.append("orange")
            else:
                node_colors.append("lightblue")
        
        for edge in G.edges:
            if edge in path_edges:
                edge_colors.append("red")
            else:
                edge_colors.append("black")
        
        plt.subplot(rows, cols, depth + 1)
        nx.draw(G, pos, with_labels=True, node_color=node_colors, edge_color=edge_colors, node_size=800)
        plt.title(f"Depth Limit = {depth}")
    
    plt.tight_layout()
    plt.show()

iddfs((0, 0), 6)
