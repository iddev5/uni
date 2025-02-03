a = int(input("Enter starting range: "))
b = int(input("Enter ending range: "))

if a > b:
    print("Invalid range")
    exit()

sum_even, sum_odd = 0, 0
for i in range(a, b):
    if i % 2 == 0:
        sum_even += i
        print(i, " = Even")
    else:
        sum_odd += i
        print(i, " = Odd")

print("Sum of even:", sum_even)
print("Sum of odd:", sum_odd)