
# f = open('demofile.txt', 'r')

# i = f.readline()
# while i:
#     print(i, end='')
#     i = f.readline()

# f.close()

# f = open('demofile.txt', 'a')
# f.write("VSSUT has NIRF Ranking")
# f.close()

# f = open('demofile.txt', 'w')
# f.write('This is IIT Kharagpur')
# f.close()

# f = open('demofile.txt', 'r')
# print(f.read())
# f.close()

# import os

# # os.remove('demofile.txt')

# os.rmdir("testfolder")




f = open('demofile.txt', 'r')
lines = f.readlines()
words = []
for i in range(len(lines)):
    words.append(len(lines[i].split()))

f.close()

f = open('newfile.txt', 'w')
for w in words:
    f.write(str(w) + '\n')
f.close()