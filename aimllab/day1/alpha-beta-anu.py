import tkinter as tk
from collections import defaultdict

class StickTree:
    def __init__(s):
        s.r = tk.Tk()
        s.r.title("Alpha-Beta")
        s.r.geometry("900x600")
        s.g, s.p, s.dn, s.ne, s.pb = {}, {}, defaultdict(list), 0, 0
        s.cv = tk.Canvas(s.r, bg="white", width=700, height=580)
        s.cv.pack(side="left")
        p = tk.Frame(s.r, width=200)
        p.pack(side="right", fill="y")
        s.st = tk.Label(p, text="")
        s.st.pack(pady=20)
        tk.Button(p, text="Show Path", command=s.show_path).pack()
        tk.Button(p, text="Show Pruned", command=s.show_pruned).pack()
        s.build()

    def ss(s, x): return "+".join(map(str, sorted(x, reverse=1)))

    def mv(s, x):
        m = []
        for i, v in enumerate(x):
            if v > 2:
                for a in range(1, v//2+1):
                    n = sorted(x[:i]+x[i+1:]+[a, v-a], reverse=1)
                    if s.ss(n) not in {s.ss(z) for z in m}: m.append(n)
        return m

    def ab(s, x, d, m, al=-1e9, bt=1e9):
        s.ne += 1
        k = s.ss(x)
        if k not in s.g:
            s.g[k] = {"d": d, "m": m, "c": [], "v": None, "b": None, "p": 0}
            s.dn[d].append(k)
        if all(v <= 2 for v in x):
            s.g[k]["v"] = -1 if m else 1
            return s.g[k]["v"], None
        val, best = -1e9 if m else 1e9, None
        for i, y in enumerate(s.mv(x)):
            ck = s.ss(y)
            s.g[k]["c"].append(ck)
            v, _ = s.ab(y, d+1, not m, al, bt)
            if (m and v > val) or (not m and v < val): val, best = v, y
            al, bt = (max(al, v), bt) if m else (al, min(bt, v))
            if bt <= al:
                s.pb += 1
                for z in s.mv(x)[i+1:]:
                    pk = s.ss(z)
                    s.g[pk] = {"d": d+1, "m": not m, "c": [], "v": None, "b": None, "p": 1}
                    s.dn[d+1].append(pk)
                break
        s.g[k]["v"], s.g[k]["b"] = val, best
        return val, best

    def build(s):
        s.ne = s.pb = 0
        s.ab([7], 0, 1)
        rv = s.g["7"]["v"]
        s.st.config(text=f"Nodes:{s.ne}\nPruned:{s.pb}\nWinner:{'MAX' if rv>0 else 'MIN'}")
        s.draw()

    def draw(s):
        s.cv.delete("all")
        for d, n in s.dn.items():
            y = 50 + d * 100
            w = (len(n)-1) * 120 if len(n) > 1 else 0
            x0 = (700-w)/2
            for i, k in enumerate(n): s.p[k] = (x0 + i*120, y)
        for k, v in s.g.items():
            if k in s.p:
                x, y = s.p[k]
                for c in v["c"]:
                    if c in s.p:
                        s.cv.create_line(x, y, *s.p[c], fill="gray")
        for k, v in s.g.items():
            if k in s.p:
                x, y = s.p[k]
                s.cv.create_oval(x-30, y-30, x+30, y+30, fill="#ffcccb" if v["m"] else "#add8e6")
                s.cv.create_text(x, y-5, text=f"({k})")
                if v["v"] != None: s.cv.create_text(x, y+10, text=f"v={v['v']}")

    def show_path(s):
        s.cv.delete("highlight")
        c = "7"
        while c in s.g and s.g[c]["b"]:
            n = s.ss(s.g[c]["b"])
            if c in s.p and n in s.p:
                s.cv.create_line(*s.p[c], *s.p[n], fill="green", width=3, tags="highlight")
            c = n

    def show_pruned(s):
        s.cv.delete("highlight")
        for k, v in s.g.items():
            if v.get("p") and k in s.p:
                x, y = s.p[k]
                s.cv.create_oval(x-35, y-35, x+35, y+35, outline="red", width=2, fill="", tags="highlight")

    def run(s): s.r.mainloop()

if __name__ == "__main__": StickTree().run()