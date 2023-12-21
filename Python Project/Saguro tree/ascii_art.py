


SIZE = 3


def top_tree():
    SPACE = SIZE + 6
    for row in range(1, SIZE + 1):
         print(" " * SPACE, end = "")
         print("@@" * row)
         SPACE = SPACE - 1
    print("       ======")
def middle_tree():
    SPACE = SIZE + 3
    for row in range(1,SIZE + 1):
        print(" " * SPACE, end = "")
        print("@@" * (row + SIZE))
        SPACE = SPACE - 1
    print("    ============")

def bottom_tree():
    SPACE = SIZE
    for row in range(1, SIZE  + 1):
        print(" " * SPACE, end = "")
        print("@@" * (row + SIZE * 2))
        SPACE = SPACE - 1
def tree_base():
    for row in range(1, SIZE + 1):
        print("       ``````   ")


def main():
    top_tree()
    middle_tree()
    bottom_tree()
    tree_base()
main()
