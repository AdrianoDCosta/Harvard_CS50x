import re
from cs50 import get_string
from cs50 import get_int


def main():
    text = get_string("Type your text: ")
    charaAlpha = 0

# count with built-in method isalph()
    for count in text:
        if count.isalpha():
            charaAlpha += 1

    # Regex with function findall
    sent = len(re.findall(r'\!|\?|\.', text))

    # Method split
    words = len(text.split())

    # the Coleman-Liau formula 0.0588 * L - 0.296 * S - 15.8
    grade = round((0.0588 * (charaAlpha/words*100)) - (0.296 * (sent/words*100)) - 15.8)

    if (grade >= 16):
        print("Grade 16+\n")
    elif (grade >= 0 and grade <= 15):
        print("Grade: ", + grade)
    else:
        print("Before Grade 1")


if __name__ == "__main__":
    main()
