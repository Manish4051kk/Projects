
#This program prints a saguaro cactus of any size.



#This defines the size of the cactus
SIZE = 3




#this prints the top of the cactus

def top_cactus():
    
    print(" " + "x" * SIZE + " " * (SIZE + 1) + "xx" * SIZE)
    number_of_dashes_top = (SIZE * 2) - 1
    for line in range(2,2 * SIZE + 1):
        print("X" + "-" * SIZE + "X" + " " * (SIZE - 1), end = "")
        print("" * (SIZE - 1) + "X" + "/" * (line - 1), end = "")
        print("-" * number_of_dashes_top, end = "")
        print("X")
        number_of_dashes_top = number_of_dashes_top - 1

#this prints the middle of the cactus

def middle_cactus():
    number_of_dashes_middle = SIZE * 2 - 1
    print(" " + "xx" * SIZE + "X" + "~~" * SIZE + "X" + " " * (SIZE + 1) + "x" * SIZE)
    for line in range(2,2 * SIZE + 1):
        print(" " * ((SIZE * 2) + 1) + "X" + "-" * number_of_dashes_middle, end = "")
        number_of_dashes_middle = number_of_dashes_middle - 1
        print("\\" * (line - 1) + "X", end = "")
        #prints right arm
        print(" " * SIZE + "X" + "-" * SIZE + "X")

#this prints the bottom of the cactus

def bottom_cactus():
    #this defines the repeated section
    def repeat_section():
        print(" " * (2 * SIZE + 1) + "X" + "~~" * SIZE + "X")
    print(" " * (2 * SIZE + 1) + "X" + "~~" * SIZE + "X" + "x" * (2 * SIZE + 1))
    for line in range(2,(SIZE * 2)):
        repeat_section()
    
    


    
#this puts all 3 pieces together
def main():
    top_cactus()
    middle_cactus()
    bottom_cactus()
    
main()
