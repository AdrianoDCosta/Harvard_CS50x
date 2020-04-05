from cs50 import SQL
from csv import reader
from sys import argv

if len(argv) < 2:
    print("Usage: Python import.py characters.csv")
    exit()

# Create database
open("students.db", "w").close()
db = SQL("sqlite:///students.db")

# create table students
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

# open datas of the characters.csv
with open(argv[1], "r") as characters:

    # create Reader
    create = reader(characters)

    # Iterate over CSV file
    for row in create:

        # get name's collumn
        if row[0] == 'name':
            continue

        # Split the full name in first = penson[0], middle = person[1], last = person[2]
        person = row[0].split()

        # Get house's collumn
        if row[1] == 'house':
            continue

        # Split the house and passes the array value row[1] to house.
        house = row[1].split()

        # Get birth's collumn
        if row[2] == 'birth':
            continue

        # Split the birth and passes the array value row[2] to birth.
        birth = row[2].split()

        # insert datas in database
        # if the .csv file does not have middle's name, insert all collumns and NULL (none) in middle's name.
        if len(person) == 2:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       person[0], None, person[1], house[0], birth[0])

        # if the .csv file have middle's name, insert all collumns.
        if len(person) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       person[0], person[1], person[2], house[0], birth[0])