# child sends v value to parent
# parent sends alpha, beta value to child
# initial value:
#   alpha = -inf (maximizer)
#   beta = +inf (minimizer)
# maximizer cond: v > alpha
# minimizer cond: v < beta
# pruning cond: alpha >= beta => dont take that part

import matplotlib.pyplot as plt
import networkx as nx
from networkx.drawing.nx_pydot import graphviz_layout

g = nx.DiGraph()

g.add_node('A', value=None)
g.add_node('B', value=None)
g.add_node('C', value=None)
g.add_node('D', value=None)
g.add_node('E', value=None)
g.add_node('F', value=None)
g.add_node('G', value=None)

g.add_node(8, value=2)
g.add_node(9, value=3)
g.add_node(10, value=5)
g.add_node(11, value=9)
g.add_node(12, value=0)
g.add_node(13, value=1)
g.add_node(14, value=7)
g.add_node(15, value=5)

g.add_edge('A', 'B')
g.add_edge('A', 'C')
g.add_edge('B', 'D')
g.add_edge('B', 'E')
g.add_edge('C', 'F')
g.add_edge('C', 'G')

g.add_edge('D', 8)
g.add_edge('D', 9)
g.add_edge('E', 10)
g.add_edge('E', 11)
g.add_edge('F', 12)
g.add_edge('F', 13)
g.add_edge('G', 14)
g.add_edge('G', 15)

# print(list(g.successors('A')), g.nodes.data())

def calculate_values(node, values, maxl=True):
    data = dict(g.nodes.data())
    self_data = data[node]['value']
    
    for child in list(g.successors(node)):
        # print(child, '->', data[child])
        if data[child]['value'] == None:
            calculate_values(child, values, maxl=(not maxl))
        else:
            if self_data is None:
                self_data = { 'v': None, 'alpha': -1e9, 'beta': 1e9 }
            child_data = data[child]['value']
            v = child_data if isinstance(child_data, int) else child_data['v']

            print(node, self_data)

            if maxl and v > self_data['alpha']:
                self_data['v'] = v
                self_data['alpha'] = v
            elif (not maxl) and v < self_data['beta']:
                self_data['v'] = v
                self_data['beta'] = v

    values[node] = self_data


values = {}
calculate_values('A', values)
print('AFTER: ', values)
# nx.set_node_attributes(g, values)

pos = graphviz_layout(g, prog='dot')
nx.draw(g, pos, node_color='lightblue', node_size=2000, font_size=10)

node_labels = { key: f"{key}\n{val}" for key, val in nx.get_node_attributes(g, 'value').items() }
nx.draw_networkx_labels(g, pos, labels=node_labels, font_color='black')

plt.title('Alpha beta')
plt.show()