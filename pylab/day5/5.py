# WAP to find fibonacci series of a given number

def fib(n):
    a = 0
    b = 1

    for i in range(n):
        print(b, end=' ')
        a, b = b, a + b

num = int(input("Enter number: "))
fib(num)