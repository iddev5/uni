def calculate(op, a, b):
    res = 0
    if op == '+':
        res = a + b
    elif op == '-':
        res = a - b
    elif op == '*':
        res = a * b
    elif op == '/':
        res = a / b
    elif op == '%':
        res = a % b
    else:
        res = a ** b
    
    print("Result is", res)

a = int(input("Enter first value: "))
b = int(input("Enter second value: "))
op = input("Enter operation (+,-,*,/,%,**): ")

calculate(op, a, b)