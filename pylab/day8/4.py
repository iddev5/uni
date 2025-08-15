import os

print("Deleting file...")
os.remove("testfolder/demofile.txt")

print("Deleting folder...")
os.rmdir("testfolder")