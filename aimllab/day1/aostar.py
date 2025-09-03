
JUG1_CAPACITY = 4
JUG2_CAPACITY = 3
GOAL = (0, 2)

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

def aostar():
    node_info = { GOAL: heuristic_cost(GOAL) }