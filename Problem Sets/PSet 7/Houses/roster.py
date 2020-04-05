from cs50 import SQL
from sys import argv

if len(argv) < 2:
    print("Usage: Python rooster.py Name of the House")
    exit()

# passes the choice of the house made by the user in argv to the house variavel.
house = argv[1]

# Open database students.db
db = SQL("sqlite:///students.db")
person = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last, first", house)

# Prints the students's name and born
for row in person:

    # If the middle name is empty, prints name collumn without middle name + born.
    if row['middle'] == None:
        print(row["first"], row["last"], end=' ')
        print("born ", row["birth"])

    # If the middle name is not empty, prints name collumn with middle name + born.
    else:
        print(row["first"], row["middle"], row["last"], end=' ')
        print("born ", row["birth"])