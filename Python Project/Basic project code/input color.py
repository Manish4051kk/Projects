color = input("What color do you want? ")
if color == "b" or color == "B":
    print("You have chosen Blue.") 
else:
    if color == "g" or color == "G":
        print("You have chosen Green.")
    else:
        if color == "R" or color == "r":
            print("You have chosen Red.")
        else:
            if color == "Bork":
                print("Unknown color:",color)
    
            else:
                raise ValueError




##color = input("What color do you want? ")
##if color == "b" or color == "B":
##    print("You have chosen Blue.")
##elif color == "g" or color == "G":
##    print("You have chosen Green.")
##elif color == "r" or color == "R":
##    print("You have chosen Red.")
##elif color == "Bork":
##    print("Unknown color",color)
##else:
##    raise ValueError
