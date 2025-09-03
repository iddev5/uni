
def factors(num):
    factlist = []
    lo, hi = 1, num-1

    while lo != hi and lo < num and hi > 0:
        if lo + hi == num and (hi, lo) not in factlist:
            factlist.append((lo, hi))
        lo += 1
        hi -= 1

    return factlist

def add_nodes(nodes, num):
    for comp in num:
        for fact in factors(comp):
            all_facts = tuple(set(num) - set((comp,))) + fact
            all_facts = list(all_facts)
            all_facts.sort(reverse=True)

            nodes.add(tuple(all_facts))
            add_nodes(nodes, fact)

def min_max_game(num):
    nodes = set([num])
    add_nodes(nodes, num)

    print(nodes)

min_max_game((7,))