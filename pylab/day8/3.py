f = open('demofile.txt', 'a')
f.write('Some text to append')
f.close()
print("Appended data to file")

f = open('demofile.txt', 'r')
print("After append, content is:", f.read())
f.close()