import heapq
import tkinter as tk
from collections import defaultdict
from typing import Dict, List, Optional, Tuple

# Problem parameters
A, B = 4, 3
START = (0, 0)
TARGET = (2, 0)


def neighbors(s):
    a, b = s
    res = set()
    # Fill jug A, Fill jug B
    res.add((A, b))
    res.add((a, B))
    # Empty jug A, Empty jug B
    res.add((0, b))
    res.add((a, 0))
    # Pour A to B
    move = min(a, B - b)
    res.add((a - move, b + move))
    # Pour B to A
    move = min(b, A - a)
    res.add((a + move, b - move))
    return [r for r in res if 0 <= r[0] <= A and 0 <= r[1] <= B]


def h(s):
    # Manhattan distance heuristic
    return abs(s[0] - TARGET[0]) + abs(s[1] - TARGET[1])


# --- Configurable Visual Parameters ---
NODE_RADIUS = 40
FONT_SIZE = 12
H_SPACING = 150
V_SPACING = 120
INITIAL_CANVAS_W = 1000
INITIAL_CANVAS_H = 750

# Tkinter setup
root = tk.Tk()
root.title(f"A*: Water Jugs ({A},{B}) -> {TARGET}")

# Main layout: A frame for the canvas that expands, and a fixed frame for controls.
canvas_frame = tk.Frame(root)
canvas_frame.pack(side="left", fill="both", expand=True)

frame_right = tk.Frame(root, bg="#f0f0f0", width=260)
frame_right.pack(side="right", fill="y")
frame_right.pack_propagate(False)

# --- Right Panel Widgets ---

# Add informational header at the top of the right panel
info_frame = tk.Frame(frame_right, bg="#f0f0f0")
info_frame.pack(pady=10, padx=10, fill="x")

tk.Label(
    info_frame,
    text="A* algorithm for water jug problem",
    font=("Helvetica", 10, "bold"),
    bg="#f0f0f0",
).pack(anchor="w")
tk.Label(info_frame, text=f"Capacity of jug A = {A}", bg="#f0f0f0").pack(anchor="w")
tk.Label(info_frame, text=f"Capacity of jug B = {B}", bg="#f0f0f0").pack(anchor="w")
tk.Label(info_frame, text=f"Goal State = {TARGET}", bg="#f0f0f0").pack(anchor="w")

# Separator
tk.Frame(frame_right, height=2, bg="gray").pack(fill="x", padx=5)


# Create Canvas with Scrollbars inside the canvas_frame
v_scroll = tk.Scrollbar(canvas_frame, orient="vertical")
v_scroll.pack(side="right", fill="y")
h_scroll = tk.Scrollbar(canvas_frame, orient="horizontal")
h_scroll.pack(side="bottom", fill="x")

c = tk.Canvas(
    canvas_frame,
    bg="white",
    width=INITIAL_CANVAS_W,
    height=INITIAL_CANVAS_H,
    yscrollcommand=v_scroll.set,
    xscrollcommand=h_scroll.set,
)
c.pack(side="left", fill="both", expand=True)

v_scroll.config(command=c.yview)
h_scroll.config(command=c.xview)

tk.Label(
    frame_right, text="Open / Closed Sets", bg="#f0f0f0", font=("Helvetica", 12, "bold")
).pack(pady=(10, 5))

sets_text = tk.Text(
    frame_right, width=30, state="disabled", font=("Courier", 9), wrap="none"
)
sets_text.pack(pady=5, padx=5, fill="y", expand=True)

# Control buttons
btn_frame = tk.Frame(frame_right, bg="#f0f0f0")
btn_frame.pack(pady=10)
btn_run = tk.Button(btn_frame, text="Run")
btn_run.grid(row=0, column=0, padx=5)
btn_step = tk.Button(btn_frame, text="Step")
btn_step.grid(row=0, column=1, padx=5)
btn_reset = tk.Button(btn_frame, text="Reset")
btn_reset.grid(row=0, column=2, padx=5)

# Position management
positions: Dict[Tuple[int, int], Tuple[float, float]] = {}
depth_nodes: Dict[int, List[Tuple[int, int]]] = defaultdict(list)


def update_positions():
    margin = NODE_RADIUS + 20
    if not depth_nodes:
        c.config(scrollregion=(0, 0, c.winfo_width(), c.winfo_height()))
        return

    max_nodes_in_level = max((len(nodes) for nodes in depth_nodes.values()), default=1)
    graph_width = (max_nodes_in_level - 1) * H_SPACING
    max_depth = max(depth_nodes.keys())
    graph_height = max_depth * V_SPACING

    content_width = graph_width + 2 * margin
    content_height = graph_height + 2 * margin

    canvas_w = c.winfo_width()
    canvas_h = c.winfo_height()

    scroll_w = max(content_width, canvas_w)
    scroll_h = max(content_height, canvas_h)

    y_offset = margin

    for depth, nodes in depth_nodes.items():
        n = len(nodes)
        level_width = (n - 1) * H_SPACING
        level_start_x = (scroll_w - level_width) / 2
        for i, s in enumerate(nodes):
            x = level_start_x + i * H_SPACING
            y = y_offset + depth * V_SPACING
            positions[s] = (x, y)

    c.config(scrollregion=(0, 0, scroll_w, scroll_h + 2 * margin))


# Drawing helpers
def draw_node(s, f_val=None, g_val=None, h_val=None, color="#dff5ff"):
    if s not in positions:
        return
    x, y = positions[s]
    # Draw the circle
    c.create_oval(
        x - NODE_RADIUS,
        y - NODE_RADIUS,
        x + NODE_RADIUS,
        y + NODE_RADIUS,
        fill=color,
        outline="orange",
        width=3,
    )
    # State inside the circle
    c.create_text(x, y, text=f"{s[0]},{s[1]}", font=("Arial", FONT_SIZE, "bold"))
    # g, h, f values in one line below
    if f_val is not None:
        c.create_text(
            x,
            y + NODE_RADIUS + 12,  # slightly below the circle
            text=f"g = {g_val}, h = {h_val}, f = {f_val}",
            font=("Arial", FONT_SIZE - 3),
        )


def draw_arrow(p, q, color="black", width=1):
    if p not in positions or q not in positions:
        return
    xp, yp = positions[p]
    xq, yq = positions[q]
    from math import atan2, cos, sin

    ang = atan2(yq - yp, xq - xp)
    xp2 = xp + NODE_RADIUS * cos(ang)
    yp2 = yp + NODE_RADIUS * sin(ang)
    xq2 = xq - NODE_RADIUS * cos(ang)
    yq2 = yq - NODE_RADIUS * sin(ang)
    c.create_line(xp2, yp2, xq2, yq2, arrow=tk.LAST, fill=color, width=width)


# A* variables and state
open_heap = []
open_set = {}
closed_set = {}
came_from: Dict[Tuple[int, int], Optional[Tuple[int, int]]] = {}
g_score: Dict[Tuple[int, int], int] = {}
running = False


def reset_algorithm_state():
    global running
    running = False
    c.delete("all")
    positions.clear()
    depth_nodes.clear()
    open_heap.clear()
    open_set.clear()
    closed_set.clear()
    came_from.clear()
    g_score.clear()
    sets_text.config(state="normal")
    sets_text.delete("1.0", tk.END)
    sets_text.config(state="disabled")


def update_sets_text():
    sets_text.config(state="normal")
    sets_text.delete("1.0", tk.END)
    open_sorted = sorted(open_set.items(), key=lambda item: item[1][0])
    sets_text.insert(tk.END, "OPEN:\n")
    for s, (f_val, g_val, h_val) in open_sorted:
        sets_text.insert(tk.END, f"({s[0]}, {s[1]}): {g_val}/{h_val}/{f_val}\n")
    sets_text.insert(tk.END, "\nCLOSED:\n")
    for s, (f_val, g_val, h_val) in sorted(closed_set.items()):
        sets_text.insert(tk.END, f"({s[0]}, {s[1]}): {g_val}/{h_val}/{f_val}\n")
    sets_text.config(state="disabled")


def redraw_canvas():
    c.delete("all")
    for child, parent in came_from.items():
        if parent is not None:
            draw_arrow(parent, child, color="orange", width=2)
    for s, vals in closed_set.items():
        draw_node(s, *vals, color="#a8d1f0")
    for s, vals in open_set.items():
        draw_node(s, *vals, color="#ffd6a5")
    if START in open_set or START in closed_set:
        vals = open_set.get(START, closed_set.get(START))
        if vals:
            draw_node(START, *vals, color="#9fe6a0")
    if TARGET in closed_set:
        draw_node(TARGET, *closed_set[TARGET], color="#9fe6a0")


def a_star_step():
    if not open_heap:
        return False
    f_val, g_val, current = heapq.heappop(open_heap)
    if current not in open_set:
        return True

    del open_set[current]
    closed_set[current] = (f_val, g_val, h(current))

    if current == TARGET:
        redraw_canvas()
        path = []
        curr = TARGET
        while curr is not None:
            path.append(curr)
            curr = came_from.get(curr)
        path.reverse()
        for i in range(len(path) - 1):
            draw_arrow(path[i], path[i + 1], color="red", width=3)
        return False

    for neighbor in neighbors(current):
        tentative_g = g_val + 1
        if tentative_g < g_score.get(neighbor, float("inf")):
            g_score[neighbor] = tentative_g
            came_from[neighbor] = current
            f_neighbor = tentative_g + h(neighbor)
            if neighbor not in open_set and neighbor not in closed_set:
                heapq.heappush(open_heap, (f_neighbor, tentative_g, neighbor))
                open_set[neighbor] = (f_neighbor, tentative_g, h(neighbor))
                if tentative_g not in depth_nodes:
                    depth_nodes[tentative_g] = []
                if neighbor not in depth_nodes[tentative_g]:
                    depth_nodes[tentative_g].append(neighbor)

    update_positions()
    redraw_canvas()
    update_sets_text()
    return True


def run_animation():
    global running
    if running:
        return
    running = True

    def loop():
        global running
        if running and a_star_step():
            root.after(300, loop)
        else:
            running = False

    loop()


def step_once():
    global running
    running = False
    a_star_step()


def do_reset():
    global running
    running = False
    reset_algorithm_state()
    g_score[START] = 0
    came_from[START] = None
    heapq.heappush(open_heap, (h(START), 0, START))
    open_set[START] = (h(START), 0, h(START))
    depth_nodes[0] = [START]
    update_positions()
    redraw_canvas()
    update_sets_text()


btn_run.config(command=run_animation)
btn_step.config(command=step_once)
btn_reset.config(command=do_reset)

do_reset()
root.mainloop()
