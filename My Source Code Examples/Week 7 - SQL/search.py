# import library csv
import csv

# prompt user for title
title = input("Please, type the title you want to search in Shows1.csv: ")

# Open csv file
with open("shows1.csv", "r") as input:

    # Create DictReader
    reader = csv.DictReader(input)

    # Iterate over CSV file
    for row in reader:
        
        # search the title
        if title == row["primaryTitle"]:
            print(row["primaryTitle"], row["startYear"])
