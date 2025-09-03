# wap to implement a* search algorithm on water jug problem

JUG1_CAPACITY, JUG2_CAPACITY, GOAL = 4, 3, (2, 0)

start = (0, 0)
current_node = None

def get_successors(state):
    a, b = state
    p1, p2 = min(a, JUG2_CAPACITY - b), min(b, JUG1_CAPACITY - a)
    return [
        (JUG1_CAPACITY, b), (a, JUG2_CAPACITY),
        (0, b), (a, 0),
        (a - p1, b + p1), (a + p2, b - p2)
    ]

def heuristic_cost(n):
    x, y = n
    if 0 < x and x < 4 and 0 < y and y < 3:
        return 2
    elif (0 < x and x < 4) or (0 < y and y < 3):
        return 4
    elif (x == 0 and y == 0) or (x == 4 and y == 3):
        return 10
    elif (x == 0 and y == 3) or (x == 4 and y == 0):
        return 8
    else:
        return None

pred = {start: None}

def depth(pred, node):
    d = 0
    while pred.get(node) is not None:
        node = pred[node]
        d += 1
    return d

def total_cost(n):
    return depth(start, n) + heuristic_cost(n)

def astar():
    openlist = set([start])
    closelist = set([])
    costs = {start: total_cost(start)}

    while openlist:
        n = openlist.pop()
        if n == GOAL:
            return n
        else:
            closelist.add(n)

            exists = 0
            for succ in get_successors(n):
                if succ in openlist:
                    exists = 1
                elif succ in closelist:
                    exists = 2

            if exists == 0:
                for succ in get_successors(n):
                    costs[succ] = total_cost(succ)
                    pred[succ] = n # Might be multiple parents

            elif exists == 1:
                for succ in get_successors(n):
                    if total_cost(succ):
                        pass

            else:
                for succ in get_successors(n):
                    if total_cost(succ):
                        pass

