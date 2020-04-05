from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        width = height
        if height >= 1 and height <= 8:
            break
        elif height >= 10 and height <= 23:
            break

    for row in range(1, height + 1):
        # add hashes
        hashes = row
        # add spaces
        spaces = width - hashes

        # print spaces right
        print(" " * spaces, end="")

        # print hashes right
        print("#" * hashes)


if __name__ == "__main__":
    main()