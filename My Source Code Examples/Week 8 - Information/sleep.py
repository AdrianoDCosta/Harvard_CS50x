from time import sleep
from cs50 import get_string

text = get_string("Text: ")

for i in text:
    
    if i[0] == 'h':
        for i in range(00, 50):
            print(f"Checking {i}...")
            sleep(.1)
    else:
        print(f"Your text is: {text}")
