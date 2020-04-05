from cs50 import get_string

question = get_string("Do you agree?\n")

if question.lower() in ["y", "yes"]:
    print("Agreed.")
elif question.lower() in ["n", "no"]:
    prin("Not agree.")
