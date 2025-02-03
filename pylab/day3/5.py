
month = input("Enter month name: ")

months = ['january', 'february', 'march', 'april', 'may', 'june', 
          'july', 'august', 'september', 'october', 'november', 'december']

i = 0
while i < len(months):
    if month.lower() == months[i]:
        break
    i += 1

if i >= 7:
    i += 1

days = 30
if i == 1:
    days = 28
elif i % 2 == 0:
    days = 31

print(f"{month} month has {days} days")

