import os

s = input("Enter data to enter into file: ")

if os.path.exists('demofile.txt'):
    print("File already exists")
    print("Deleting file")
    os.remove('demofile.txt')

f = open('demofile.txt', 'x')
f.write(s)
f.close()

print("Created new file")