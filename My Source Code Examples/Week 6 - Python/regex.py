import re
from cs50 import get_string

question = get_string("Do you agree?\n")

# "yes" "yes|y" "y(es)?"
if re.search("y(es)?", question, re.IGNORECASE):
    print("Agreed.")
elif re.search("no", question):
    prin("Not agree.")
