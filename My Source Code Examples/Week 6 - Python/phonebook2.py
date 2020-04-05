import csv
from cs50 import get_string

name = get_string("Name: ")
number = get_string("Number: ")

# a = append (acrescentar)
with open("phonebook2.csv", "a") as file:

    # Hey, Python. Pass the open file to this library
    writer = csv.writer(file)
    writer.writerow((name , number))
