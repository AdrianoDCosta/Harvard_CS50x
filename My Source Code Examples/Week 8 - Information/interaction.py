from time import sleep
from cs50 import get_string

for i in range(00, 11):
    print(f"Checking {i}...")
    sleep(.1)

text = get_string("Repeat? ")

if text == 'y':
    for i in range(11, 21):
        print(f"Checking {i}...")
        sleep(.1)
elif text == 'n':
    print("Finish.")
else:
    print("Please, type y or n")
