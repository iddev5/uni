# Program 1

D = {0: 10, 1: 20}
D[2] = 30
print(D)

# Program 2
keys = ['Ten', 'Twenty', 'Thirty']
values = [10, 20, 30]

D2 = {}

for i in range(len(keys)):
    D2[keys[i]] = values[i]

print(D2)

# Program 3
sampleDict = {
    "class": {
        "name": "mike",
        "marks": {
            "physics": 70,
            "history": 80
        }
    }
}

print(sampleDict["class"]["marks"]["history"])

# Program 4

inventory = {
    'gold': 500,
    'pouch': ['flint', 'twine', 'gemstone'],
    'backpack': ['xylophone', 'dagger', 'bedroll', 'bread loaf']
}

inventory["pocket"] = ['seashell', 'strange berry', 'lint']

inventory["backpack"].sort()

inventory["backpack"].remove('dagger')

inventory["gold"] += 50

print(inventory)