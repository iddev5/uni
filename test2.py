levels = int(input())
for i in range(levels):
    for j in range(levels - i):
        print(' ', end='')
    for j in range(2*i + 1):
        print('*', end='')
    print()