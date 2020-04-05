import csv
from cs50 import get_string

# a = append
file = open("phonebook.csv", "a")

name = get_string("Name: ")
number = get_string("Number: ")

# Hey, Python. Pass the open file to this library
writer = csv.writer(file)
writer.writerow((name , number))

file.close()
