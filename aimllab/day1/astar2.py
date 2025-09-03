import tkinter as tk
from tkinter import ttk
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import heapq

JUG1_CAPACITY, JUG2_CAPACITY, START, GOAL = 4, 3, (0, 0), (2, 0)
node_info, open, closed, parent, G = {}, [], set(), {}, nx.DiGraph()
auto_running, goal_found = False, False

def heuristic(state): return abs(state[0] - GOAL[0]) + abs(state[1] - GOAL[1])

def get_successors(state):
    a, b = state
    pour1, pour2 = min(a, JUG2_CAPACITY - b), min(b, JUG1_CAPACITY - a)
    return {(JUG1_CAPACITY, b), (a, JUG2_CAPACITY), (0, b), (a, 0), (a - pour1, b + pour1), (a + pour2, b - pour2)}

def reset_search():
    global open, closed, parent, G, node_info, goal_found, auto_running
    open, closed, parent, node_info = [], set(), {}, {}
    G.clear()
    goal_found, auto_running = False, False
    g, h, f = 0, heuristic(START), heuristic(START)
    node_info[START], parent[START] = (g, h, f), None
    heapq.heappush(open, (f, g, START))
    draw_graph()
    update_text_panel()

def step_search():
    global goal_found, auto_running
    if not open or goal_found: return
    f, g, current = heapq.heappop(open)
    closed.add(current)
    if current == GOAL:
        highlight_path()
        goal_found, auto_running = True, False
        return
    for succ in get_successors(current):
        if succ not in closed:
            new_g, new_h, new_f = g + 1, heuristic(succ), g + 1 + heuristic(succ)
            heapq.heappush(open, (new_f, new_g, succ))
            if succ not in parent:
                parent[succ], node_info[succ] = current, (new_g, new_h, new_f)
                G.add_edge(current, succ)
    draw_graph(current)
    update_text_panel()

def auto_step():
    if auto_running and not goal_found:
        step_search()
        root.after(500, auto_step)

def start_auto():
    global auto_running
    if not auto_running:
        auto_running = True
        auto_step()

def stop_auto(): global auto_running; auto_running = False

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

def get_tree_pos(G, root):
    pos = {}
    assign_pos(G, root, pos)
    return pos

def draw_graph(current=None):
    ax.clear()
    if START not in G.nodes(): G.add_node(START)
    pos = get_tree_pos(G, START)
    node_colors = ["yellow" if node == current else "lightblue" if node in closed else "white" for node in G.nodes()]
    labels = {n: f"{n}\ng={g}, h={h}, f={f}" for n, (g, h, f) in node_info.items()}
    nx.draw(G, pos, ax=ax, with_labels=True, labels=labels, node_color=node_colors, node_size=1500, font_size=8)
    canvas.draw()

def highlight_path():
    path, node = [], GOAL
    while node: path.append(node); node = parent.get(node)
    path.reverse()
    ax.clear()
    pos = get_tree_pos(G, START)
    labels = {n: f"{n}\ng={g}, h={h}, f={f}" for n, (g, h, f) in node_info.items()}
    nx.draw(G, pos, ax=ax, with_labels=True, labels=labels, node_color="lightblue", node_size=1500, font_size=8)
    nx.draw_networkx_nodes(G, pos, nodelist=path, node_color="pink", node_size=2000, ax=ax)
    nx.draw_networkx_edges(G, pos, edgelist=list(zip(path, path[1:])), edge_color="red", width=2, ax=ax)
    canvas.draw()

def update_text_panel():
    text_widget.delete("1.0", tk.END)
    text_widget.insert(tk.END, "OPEN LIST:\n")
    for f, g, node in sorted(open):
        g, h, f = node_info.get(node, (g, heuristic(node), f))
        text_widget.insert(tk.END, f"{node} -> g={g}, h={h}, f={f}\n")
    text_widget.insert(tk.END, "\nCLOSED LIST:\n")
    for node in closed:
        g, h, f = node_info.get(node, ("?", "?", "?"))
        text_widget.insert(tk.END, f"{node} -> g={g}, h={h}, f={f}\n")

root = tk.Tk()
root.title("A* Water Jug Problem")
left_frame, right_frame = ttk.Frame(root), ttk.Frame(root, width=200)
left_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
right_frame.pack(side=tk.RIGHT, fill=tk.Y)
frame = ttk.Frame(left_frame)
frame.pack(side=tk.TOP, fill=tk.X)

ttk.Button(frame, text="Step", command=step_search).pack(side=tk.LEFT, padx=5, pady=5)
ttk.Button(frame, text="Auto Step", command=start_auto).pack(side=tk.LEFT, padx=5, pady=5)
ttk.Button(frame, text="Stop", command=stop_auto).pack(side=tk.LEFT, padx=5, pady=5)
ttk.Button(frame, text="Reset", command=reset_search).pack(side=tk.LEFT, padx=5, pady=5)

fig, ax = plt.subplots(figsize=(8, 6))
canvas = FigureCanvasTkAgg(fig, master=left_frame)
canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=1)
text_widget = tk.Text(right_frame, wrap="word", width=40)
text_widget.pack(side=tk.TOP, fill=tk.BOTH, expand=True, padx=5, pady=5)

reset_search()
root.mainloop()
