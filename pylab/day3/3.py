mylist = ['apple', 'banana', 'carrot', 'gdp', 'test', 'experiment', 'seven', 'stop', 'ppp']

for elem in mylist:
    test = False
    cases = ['a', 'e', 'i', 'o', 'u']
    for case in cases:
        if case in elem:
            test = True

    if test:
        print(elem, 'contains vowels')
    else:
        print(elem, 'does not contain vowels')