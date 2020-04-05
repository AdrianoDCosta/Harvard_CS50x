from cs50 import get_string

# Example  with + variable
answer = get_string("What's your name?\n")
print("Hello, " + answer)

# Example with , (comma) variable
answer2 = get_string("How are you?\n")
print("Your answer is: ", answer2)

#example with f {variable}
answer3 = get_string("Where you live?\n")
print(f"You lives in: {answer3}")

# Example with input
answer = input("What's your name again?\n")
print(f"Hello, {answer}")
