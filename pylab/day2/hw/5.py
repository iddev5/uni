print("First 10 odd numbers:")
i = 0
count = 0
while count < 10:
    if i % 2 != 0:
        print(i, end=", ")
        count += 1
    i += 1