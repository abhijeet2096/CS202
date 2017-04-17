"""
    Generate input date for sorting to work upon.
    - sahilarora.535
"""
import os
import random


def main():
    sizes = [100, 500, 1000, 5000, 10000,
             50000, 100000, 500000, 1000000, 5000000]
    types = ["rand", "asc", "desc"]
    directory = "input"
    if not os.path.exists(directory):
        os.makedirs(directory)

    for i in sizes:
        random_list = random.sample(range(-i, i), i)
        for order in types:
            filename = directory + "/" + order + "_" + str(i) + ".in"
            f = open(filename, "w")
            f.write(str(i) + "\n")
            if order == "asc":
                random_list.sort()
            elif order == "desc":
                random_list.sort()
                random_list.reverse()
            for x in random_list:
                f.write(str(x) + "\n")
            f.close()


if __name__ == "__main__":
    main()
