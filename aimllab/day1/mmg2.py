# Minimax Sum-Split Game (Tkinter + NetworkX + Matplotlib)
# - No classes; globals to keep it simple
# - Legal move: pick one part x>=2, split x into a+b for all a in [1..x-1]
# - Tree finite via MAX_DEPTH; leaves scored by leaf_value(state)
# - Minimax alternates by depth: depth 0 = MAX (root), 1 = MIN, ...

import tkinter as tk
from tkinter import ttk
import threading  # not used for stepping; we use Tk .after()
import time
import math
import networkx as nx
import matplotlib
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

# -------------- Globals --------------
ROOT = None
START_N = 7
MAX_DEPTH = 3        # can be changed via UI
AUTO_INTERVAL_MS = 700

# Game structures
NODES = []           # list of dicts: {id, state(tuple), depth, children([ids]), value}
G = None             # networkx.DiGraph
POS = None           # layout positions
POSTORDER = []       # node ids in post-order for stepwise minimax
EVAL_INDEX = 0
RUNNING = False
AFTER_ID = None
CURRENT_NODE = None  # for highlight

# Matplotlib in Tk
FIG = None
AX = None
CANVAS = None

# Widgets
start_entry = None
depth_spin = None
result_var = None

# -------------- Game / Tree --------------

def split_pairs(x):
    """All splits a+b=x with a<=b (to avoid duplicates like 1+6 and 6+1)."""
    pairs = []
    lo, hi = 1, x - 1
    while lo <= hi:
        pairs.append((lo, hi))
        lo += 1
        hi -= 1
    return pairs

def leaf_value(state):
    """Utility function at leaves: product of parts."""
    prod = 1
    for v in state:
        prod *= v
    return prod

def new_node(state, depth):
    nid = len(NODES)
    node = {
        "id": nid,
        "state": tuple(sorted(state, reverse=True)),  # keep labels neat
        "depth": depth,
        "children": [],
        "value": None
    }
    NODES.append(node)
    return nid

def build_tree(state, depth, max_depth):
    """Build a *path-distinct* game tree (don’t merge identical states)."""
    nid = new_node(state, depth)

    if depth >= max_depth:
        return nid

    # Expand: pick each component >=2 and split
    for idx, comp in enumerate(state):
        if comp < 2:
            continue
        for a, b in split_pairs(comp):
            new_state = list(state)
            # remove the chosen component at this index
            del new_state[idx]
            # add the split parts
            new_state.extend([a, b])
            child_id = build_tree(new_state, depth + 1, max_depth)
            NODES[nid]["children"].append(child_id)
    return nid

def build_graph(root_id):
    """Fill the NetworkX DiGraph with nodes/edges, annotate level=depth."""
    global G
    G = nx.DiGraph()
    for node in NODES:
        G.add_node(node["id"], level=node["depth"])
    for node in NODES:
        for ch in node["children"]:
            G.add_edge(node["id"], ch)

def postorder_list(nid, out):
    for ch in NODES[nid]["children"]:
        postorder_list(ch, out)
    out.append(nid)

def compute_postorder(root_id):
    out = []
    postorder_list(root_id, out)
    return out

# -------------- Minimax step --------------

def is_max(depth):
    return (depth % 2) == 0  # root depth 0 = MAX

def eval_one(nid):
    """Evaluate a single node assuming all children already evaluated."""
    node = NODES[nid]
    if not node["children"]:  # leaf (by depth or no splits)
        node["value"] = leaf_value(node["state"])
        return

    child_vals = [NODES[c]["value"] for c in node["children"]]
    if any(v is None for v in child_vals):
        return  # shouldn't happen if we follow postorder

    node["value"] = max(child_vals) if is_max(node["depth"]) else min(child_vals)

# -------------- Drawing --------------

def label_for(node):
    expr = "+".join(map(str, node["state"]))
    role = "MAX" if is_max(node["depth"]) else "MIN"
    if node["value"] is None:
        return f"{expr}\n({role})"
    return f"{expr}\n({role})\n= {node['value']}"

def draw_graph(highlight_id=None):
    AX.clear()

    # layout across rows by depth (no graphviz)
    pos = nx.multipartite_layout(G, subset_key="level", align="horizontal")

    # node colors (evaluated vs not), with optional highlight
    colors = []
    for nid in G.nodes():
        if highlight_id is not None and nid == highlight_id:
            colors.append("salmon")
        else:
            colors.append("lightgreen" if NODES[nid]["value"] is not None else "lightblue")

    labels = {nid: label_for(NODES[nid]) for nid in G.nodes()}
    nx.draw(
        G, pos,
        with_labels=True, labels=labels,
        node_size=2600, node_color=colors,
        font_size=8, font_weight="bold",
        arrows=False, ax=AX
    )

    AX.set_title(f"Minimax Sum-Split Tree (n={START_N}, depth={MAX_DEPTH})")
    CANVAS.draw()

# -------------- Controls --------------

def step_once():
    global EVAL_INDEX, CURRENT_NODE, RUNNING, AFTER_ID
    if EVAL_INDEX >= len(POSTORDER):
        RUNNING = False
        CURRENT_NODE = None
        draw_graph()
        root_val = NODES[0]["value"]
        result_var.set(f"Final minimax value: {root_val}")
        return

    nid = POSTORDER[EVAL_INDEX]
    CURRENT_NODE = nid
    eval_one(nid)
    EVAL_INDEX += 1
    draw_graph(highlight_id=nid)

    if EVAL_INDEX >= len(POSTORDER):
        # finished
        RUNNING = False
        CURRENT_NODE = None
        root_val = NODES[0]["value"]
        result_var.set(f"Final minimax value: {root_val}")

def auto_tick():
    global RUNNING, AFTER_ID
    if not RUNNING:
        return
    step_once()
    if RUNNING:
        AFTER_ID = ROOT.after(AUTO_INTERVAL_MS, auto_tick)

def start_auto():
    global RUNNING, AFTER_ID
    if RUNNING:
        return
    RUNNING = True
    AFTER_ID = ROOT.after(AUTO_INTERVAL_MS, auto_tick)

def stop_auto():
    global RUNNING, AFTER_ID
    RUNNING = False
    if AFTER_ID is not None:
        try:
            ROOT.after_cancel(AFTER_ID)
        except Exception:
            pass

def reset():
    """Rebuild tree/graph from UI values and redraw."""
    global START_N, MAX_DEPTH
    global NODES, G, POS, POSTORDER, EVAL_INDEX, RUNNING, AFTER_ID, CURRENT_NODE
    stop_auto()

    # read UI
    try:
        START_N = int(start_entry.get())
    except Exception:
        START_N = 7
        start_entry.delete(0, tk.END)
        start_entry.insert(0, "7")

    try:
        MAX_DEPTH = int(depth_spin.get())
    except Exception:
        MAX_DEPTH = 3

    # rebuild
    NODES = []
    root_id = build_tree([START_N], depth=0, max_depth=MAX_DEPTH)
    build_graph(root_id)
    POSTORDER = compute_postorder(root_id)
    EVAL_INDEX = 0
    CURRENT_NODE = None
    result_var.set("Final minimax value: —")
    draw_graph()

# -------------- Tk App --------------

ROOT = tk.Tk()
ROOT.title("Minimax Sum-Split Game — Tkinter + NetworkX + Matplotlib (No Graphviz)")

# Top controls
ctrl = tk.Frame(ROOT)
ctrl.pack(side=tk.TOP, fill=tk.X, pady=6)

tk.Label(ctrl, text="Start n:").pack(side=tk.LEFT, padx=(8,4))
start_entry = tk.Entry(ctrl, width=6)
start_entry.pack(side=tk.LEFT)
start_entry.insert(0, str(START_N))

tk.Label(ctrl, text="Max Depth:").pack(side=tk.LEFT, padx=(12,4))
depth_spin = tk.Spinbox(ctrl, from_=1, to=7, width=5)
depth_spin.pack(side=tk.LEFT)
depth_spin.delete(0, tk.END)
depth_spin.insert(0, str(MAX_DEPTH))

ttk.Button(ctrl, text="Start (Auto)", command=start_auto).pack(side=tk.LEFT, padx=6)
ttk.Button(ctrl, text="Step", command=step_once).pack(side=tk.LEFT, padx=6)
ttk.Button(ctrl, text="Stop", command=stop_auto).pack(side=tk.LEFT, padx=6)
ttk.Button(ctrl, text="Reset", command=reset).pack(side=tk.LEFT, padx=6)

result_var = tk.StringVar(value="Final minimax value: —")
tk.Label(ROOT, textvariable=result_var, font=("TkDefaultFont", 10, "bold")).pack(pady=(0,6))

# Matplotlib figure embedded in Tk
matplotlib.use("TkAgg")
FIG, AX = plt.subplots(figsize=(9, 6))
CANVAS = FigureCanvasTkAgg(FIG, master=ROOT)
CANVAS.get_tk_widget().pack(fill=tk.BOTH, expand=True)

# Init
reset()
ROOT.mainloop()

