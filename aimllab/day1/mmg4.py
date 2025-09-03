import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import networkx as nx

# Global variables
root = None
fig = None
ax = None
canvas = None
is_running = False
generation_done = False
G = None
frontier = None
added_nodes = None
node_values = None
traversal_queue = None
start_state = (9,)
start_button = None

def factors(num):
    if num < 2:
        return []
    factlist = []
    for lo in range(1, (num // 2) + 1):
        hi = num - lo
        factlist.append((lo, hi))
    return factlist

def get_player(state):
    k = len(state)
    return 'max' if (k - 1) % 2 == 0 else 'min'

def generate_step():
    global generation_done, traversal_queue, node_values
    if frontier:
        parent = frontier.pop(0)
        for comp_idx, comp in enumerate(parent):
            if comp < 2:
                continue
            for a, b in factors(comp):
                if a > b:
                    a, b = b, a
                new_list = list(parent[:comp_idx] + parent[comp_idx + 1:]) + [a, b]
                new_list.sort(reverse=True)
                child = tuple(new_list)
                if child not in added_nodes:
                    added_nodes.add(child)
                    frontier.append(child)
                if not G.has_edge(parent, child):
                    G.add_edge(parent, child)
    else:
        if not generation_done:
            generation_done = True
            node_values = {}
            traversal_queue = []
            for node in list(G.nodes):
                if G.out_degree(node) == 0:
                    node_values[node] = -1 if get_player(node) == 'max' else 1
                    traversal_queue.append(node)

def traversal_step():
    if traversal_queue:
        node = traversal_queue.pop(0)
        for pred in list(G.predecessors(node)):
            if all(ch in node_values for ch in G.successors(pred)) and pred not in node_values:
                child_vals = [node_values[ch] for ch in G.successors(pred)]
                if get_player(pred) == 'max':
                    val = max(child_vals)
                else:
                    val = min(child_vals)
                node_values[pred] = val
                traversal_queue.append(pred)

def step():
    if not generation_done:
        generate_step()
    else:
        traversal_step()
    draw_graph()

def toggle_run():
    global is_running
    is_running = not is_running
    if is_running:
        start_button.config(text='Stop')
        auto()
    else:
        start_button.config(text='Start')

def auto():
    if is_running:
        step()
        root.after(500, auto)

def reset():
    global generation_done, is_running
    is_running = False
    start_button.config(text='Start')
    init_graph()
    generation_done = False
    draw_graph()

def init_graph():
    global G, frontier, added_nodes, node_values, traversal_queue
    G = nx.DiGraph()
    frontier = [start_state]
    added_nodes = set([start_state])
    G.add_node(start_state)
    node_values = {}
    traversal_queue = []

def draw_graph():
    ax.clear()
    pos = {}
    level = {start_state: 0}
    queue = [start_state]
    while queue:
        node = queue.pop(0)
        if node not in pos:
            level_size = sum(1 for n in G.nodes if level.get(n, float('inf')) == level[node])
            pos[node] = (level[node] * 2, -list(G.nodes).index(node) / level_size if level_size > 1 else 0)
        for child in G.successors(node):
            if child not in level:
                level[child] = level[node] + 1
                queue.append(child)
    labels = {}
    for n in G.nodes:
        s = '+'.join(map(str, n))
        p = get_player(n)
        v = f' [{node_values[n]}]' if n in node_values else ''
        labels[n] = f'{p}\n{s}{v}'
    nx.draw(G, pos, ax=ax, node_color='lightblue', arrows=True, node_size=800)
    nx.draw_networkx_labels(G, pos, labels, ax=ax, font_size=6)
    canvas.draw()

def main():
    global root, fig, ax, canvas, start_button
    root = tk.Tk()
    root.title("Min-Max Game Algorithm")
    fig = plt.Figure(figsize=(10, 8))
    ax = fig.add_subplot(111)
    canvas = FigureCanvasTkAgg(fig, master=root)
    canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)
    button_frame = tk.Frame(root)
    button_frame.pack()
    start_button = tk.Button(button_frame, text='Start', command=toggle_run)
    start_button.pack(side=tk.LEFT)
    step_button = tk.Button(button_frame, text='Step', command=step)
    step_button.pack(side=tk.LEFT)
    reset_button = tk.Button(button_frame, text='Reset', command=reset)
    reset_button.pack(side=tk.LEFT)
    init_graph()
    draw_graph()
    root.mainloop()

if __name__ == "__main__":
    main()
