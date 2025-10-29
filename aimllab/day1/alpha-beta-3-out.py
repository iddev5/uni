import matplotlib.pyplot as plt
import networkx as nx

G = nx.DiGraph()
root = (7,)
trace, values, abv, levels = [], {}, {}, {}

def factors(n): return [(i, n - i) for i in range(1, n) if i < n - i]

def make_child(p, c, f):
    s = list(p); s.remove(c); s.extend(f)
    return tuple(sorted(s, reverse=True))

def expand(start):
    v, q, steps = {start: 0}, [(start, 0)], []
    while q:
        p, d = q.pop(0)
        for c in p:
            for f in factors(c):
                ch = make_child(p, c, f)
                if ch not in v: v[ch], q = d + 1, q + [(ch, d + 1)]
                if v[ch] == d + 1: steps.append((p, ch, d + 1))
    return steps, v

def positions(lv):
    pos, m = {}, max(lv.values())
    for d in range(m + 1):
        ns = sorted([n for n in lv if lv[n] == d])
        for i, n in enumerate(ns): pos[n] = ((i + 1) / (len(ns) + 1), -d)
    return pos

def alphabeta(n, d, a, b, maxing, path):
    if not list(G.successors(n)):
        v = 1 if d % 2 == 0 else -1
        values[n], abv[n] = v, (a, b, v)
        trace.append(path + [(n, a, b, v)])
        return v
    v = float('-inf') if maxing else float('inf')
    abv[n] = (a, b, v)
    for ch in G.successors(n):
        val = alphabeta(ch, d + 1, a, b, not maxing, path + [(n, a, b, v)])
        if maxing: v, a = max(v, val), max(a, val)
        else: v, b = min(v, val), min(b, val)
        abv[n] = (a, b, v)
        trace.append(path + [(n, a, b, v), (ch, a, b, val)])
        if b <= a: break
    values[n] = v
    return v

def draw(step, hl=None):
    plt.clf()
    labs, cols = {}, []
    for n in G.nodes():
        v = values.get(n, "")
        a, b, x = abv.get(n, ("", "", ""))
        labs[n] = f"{'+'.join(map(str,n))}\nv={x}\nα={a}\nβ={b}"
        cols.append("yellow" if hl and any(p[0]==n for p in hl)
                    else ("lightgreen" if v==1 else "lightcoral" if v==-1 else "lightblue"))
    nx.draw(G, pos, labels=labs, node_color=cols, node_size=1400, with_labels=True, font_size=7)
    plt.title(f"Step {step}")
    plt.axis("off"); plt.tight_layout()
    plt.savefig(f"alpha-beta/step{step}.png")

steps, levels = expand(root)
for p,c,_ in steps: G.add_edge(p,c)
pos = positions(levels)
alphabeta(root, 0, float('-inf'), float('inf'), True, [])
for i, p in enumerate(trace, 1): draw(i, p)
