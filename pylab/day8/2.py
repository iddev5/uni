f = open('demofile.txt', 'r')
print("File content is:", f.read())
f.close()

f = open('demofile.txt', 'w')
f.write("Hello World")
f.close()
print("File content overwritten")