import tkinter as tk
from tkinter import ttk
import matplotlib.pyplot as plt
import networkx as nx
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

G = nx.DiGraph()
pos, node_values, expansion_steps, levels = {}, {}, [], {}
step_index, running, phase = 0, False, "expansion"
root_num, winner_var = (7,), None

def factors(num):
    return [(lo, num - lo) for lo in range(1, num) if lo < num - lo]

def make_child(parent, comp, fact):
    lst = list(parent)
    lst.remove(comp)
    lst.extend(fact)
    return tuple(sorted(lst, reverse=True))

def prepare_expansions(start):
    visited, queue, steps = {start: 0}, [(start, 0)], []
    while queue:
        parent, depth = queue.pop(0)
        for comp in parent:
            for fact in factors(comp):
                child = make_child(parent, comp, fact)
                if child not in visited:
                    visited[child] = depth + 1
                    queue.append((child, depth + 1))
                if visited[child] == depth + 1:
                    steps.append((parent, child, depth + 1))
    return steps, visited

def compute_positions(levels_map):
    pos_local, max_depth = {}, max(levels_map.values(), default=0)
    for d in range(max_depth + 1):
        nodes = sorted([n for n, lv in levels_map.items() if lv == d])
        for i, node in enumerate(nodes):
            pos_local[node] = ((i + 1) / (len(nodes) + 1), -d)
    return pos_local

def draw_graph():
    ax.clear()
    labels, colors = {}, []
    for n in G.nodes():
        val = node_values.get(n)
        colors.append("lightgreen" if val == 1 else "lightcoral" if val == -1 else "lightblue")
        labels[n] = f"{'+'.join(map(str, n))}\n{val if val is not None else ''}"
    nx.draw_networkx(G, pos, ax=ax, arrows=False, node_color=colors, node_size=1400, labels=labels, font_size=8)
    for d in range(max(levels.values(), default=0) + 1):
        ax.text(-0.1, -d, "Min" if d % 2 == 0 else "Max", fontsize=10, ha="right", va="center", fontweight="bold")
    ax.set_axis_off()
    ax.set_xlim(-0.2, 1.05)
    canvas.draw()

def step():
    global step_index, pos, phase
    if phase == "expansion" and step_index < len(expansion_steps):
        parent, child, _ = expansion_steps[step_index]
        G.add_node(child)
        G.add_edge(parent, child)
        pos = compute_positions(levels)
        draw_graph()
        step_index += 1
    elif phase == "expansion":
        compute_minmax()
        draw_graph()
        phase = "evaluation"
    else:
        draw_graph()

def compute_minmax():
    global node_values
    node_values, max_depth = {}, max(levels.values(), default=0)
    for n in G.nodes():
        if not G.out_degree(n):
            node_values[n] = 1 if levels[n] % 2 == 0 else -1
    for depth in range(max_depth - 1, -1, -1):
        for n, d in levels.items():
            if d == depth:
                children = [node_values[c] for c in G.successors(n) if c in node_values]
                if children:
                    node_values[n] = min(children) if d % 2 == 0 else max(children)
    root_val = node_values.get(root_num)
    winner_var.set("Result: Min wins" if root_val == 1 else "Result: Max wins" if root_val == -1 else "")

root = tk.Tk()
root.title("Min-Max Game")

frame = ttk.Frame(root); 
frame.pack(side=tk.TOP, fill=tk.BOTH, expand=True)
fig, ax = plt.subplots(figsize=(10, 6))
canvas = FigureCanvasTkAgg(fig, master=frame); 
canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)

ttk.Button(frame, text="Step", command=step).pack(side=tk.BOTTOM, padx=5)
winner_var = tk.StringVar()
ttk.Label(root, textvariable=winner_var, font=("Arial", 12, "bold")).pack(side=tk.BOTTOM, pady=6)

expansion_steps, levels = prepare_expansions(root_num)
pos = compute_positions(levels)
G.add_node(root_num)
draw_graph()

root.mainloop()