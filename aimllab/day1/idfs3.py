import tkinter as tk
from tkinter import ttk
import networkx as nx
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt

JUG1_CAPACITY, JUG2_CAPACITY, GOAL = 4, 3, (4, 2)

auto_running = False
current_node = None

def get_successors(state):
    a, b = state
    p1, p2 = min(a, JUG2_CAPACITY - b), min(b, JUG1_CAPACITY - a)
    return [
        (JUG1_CAPACITY, b), (a, JUG2_CAPACITY),
        (0, b), (a, 0),
        (a - p1, b + p1), (a + p2, b - p2)
    ]

def assign_pos(G, node, pos, depth=0, x=0):
    if node not in pos:
        pos[node] = (x, -depth)
        kids = list(G.successors(node))
        if len(kids) == 1:
            assign_pos(G, kids[0], pos, depth + 1, x)
        elif kids:
            start_x = x - len(kids)
            for i, k in enumerate(kids):
                assign_pos(G, k, pos, depth + 1, start_x + i * 4)

def reset():
    global G, visited, pred, frontier, depth_limit, goal_found, goal_path, current_node
    G = nx.DiGraph()
    G.add_node(start)
    visited = {start}
    pred = {start: None}
    frontier = [start]
    depth_limit = 0
    goal_found = False
    goal_path = None
    current_node = None
    log.delete(1.0, tk.END)
    log.insert(tk.END, "Reset search.\n")
    draw_graph()

def reconstruct_path(node):
    path = []
    while node is not None:
        path.append(node)
        node = pred[node]
    return list(reversed(path))

def step():
    global frontier, depth_limit, goal_found, goal_path, current_node
    if goal_found:
        log.insert(tk.END, "Goal already found.\n")
        return

    if not frontier:
        depth_limit += 1
        frontier = [start]
        visited.clear()
        visited.add(start)
        pred.clear()
        pred[start] = None
        log.insert(tk.END, f"\n--- Depth limit = {depth_limit} ---\n")

    node = frontier.pop(0)
    current_node = node
    log.insert(tk.END, f"Visited: {node}\n")
    log.see(tk.END)

    if node == GOAL:
        goal_found = True
        goal_path = reconstruct_path(node)
        log.insert(tk.END, f"Goal found! Path: {goal_path}\n")
        draw_graph()
        return

    if depth(pred, node) < depth_limit:
        for succ in get_successors(node):
            if succ not in visited:
                visited.add(succ)
                pred[succ] = node
                G.add_edge(node, succ)
                frontier.append(succ)

    draw_graph()

def auto_step():
    global auto_running
    if not auto_running:
        auto_running = True
        run_auto_step()

def stop_auto():
    global auto_running
    auto_running = False

def run_auto_step():
    if auto_running and not goal_found:
        step()
        root.after(500, run_auto_step)

def depth(pred, node):
    d = 0
    while pred.get(node) is not None:
        node = pred[node]
        d += 1
    return d

def draw_graph():
    fig.clear()
    ax = fig.add_subplot(111)
    pos = {}
    assign_pos(G, start, pos)

    node_colors = []
    for n in G.nodes:
        if n == current_node:
            node_colors.append("yellow")
        elif goal_path and n in goal_path:
            node_colors.append("orange")
        else:
            node_colors.append("lightblue")

    labels = {}
    for n in G.nodes:
        d = depth(pred, n)
        labels[n] = f"{n}\n(d={d if d is not None else '?'})"

    edge_colors = ["red" if goal_path and e in zip(goal_path, goal_path[1:]) else "black" for e in G.edges]

    nx.draw(G, pos, ax=ax, with_labels=True, labels=labels,
            node_color=node_colors, edge_color=edge_colors, node_size=2000)
    canvas.draw()

root = tk.Tk()
root.title("IDDFS Stepper")

frame = ttk.Frame(root)
frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
log = tk.Text(root, height=20, width=40)
log.pack(side=tk.RIGHT, fill=tk.BOTH)

btn_frame = ttk.Frame(frame)
btn_frame.pack()
ttk.Button(btn_frame, text="Step", command=step).grid(row=0, column=0, padx=5)
ttk.Button(btn_frame, text="Auto Step", command=auto_step).grid(row=0, column=1, padx=5)
ttk.Button(btn_frame, text="Stop", command=stop_auto).grid(row=0, column=2, padx=5)
ttk.Button(btn_frame, text="Reset", command=reset).grid(row=0, column=3, padx=5)

fig = plt.Figure(figsize=(5, 5))
canvas = FigureCanvasTkAgg(fig, master=frame)
canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)

start = (0, 0)
reset()
root.mainloop()