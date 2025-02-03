

# for i in range(1, 6):
#     for j in range(1, i+1):
#         print('R', end='')
#     print()

"2"
for i in range(1, 6):
    print(' ' * (6 - i), end='')
    print('R' * (2 * i - 1))

print()

"3"
for i in range(1, 6):
    print('R' * i)
for i in range(2, 6):
    print('R' * (6 - i))

print()

"4"
for i in range(1, 6):
    print(' ' * (6 - i), end='')
    print('R' * i)
for i in range(2, 6):
    print(' ' * i, end='')
    print('R' * (6 - i))

print()

"5"
for i in range(1, 6):
    print(' ' * i, end='')
    print('R' * ((6 - i) * 2 - 1))

print()

"6"
for i in range(6):
    print('R' * 6)

print()


"7"
for i in range(1, 6):
    print(' ' * i, end='')
    print('R' * ((6 - i) * 2 - 1))
for i in range(1, 6):
    print(' ' * (6 - i), end='')
    print('R' * (2 * i - 1))

print()

"8"
for i in range(1, 6):
    print('R' * i, end='')
    print(' ' * (10 - 2 * i), end='')
    print('R' * i)
for i in range(2, 6):
    print('R' * (6 - i), end='')
    print(' ' * 2 * (i - 1), end='')
    print('R' * (6 - i))
