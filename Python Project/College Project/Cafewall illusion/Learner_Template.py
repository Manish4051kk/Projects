import turtle
import Lab2_functions  # Import your custom module

# set mortar joints between rows
MORTAR = 2

def main():

    turtle.setworldcoordinates(0, 400, 650, 0)
    turtle.clear()
    turtle.shape('turtle')
    turtle.pencolor('olive drab')
    turtle.fillcolor('sienna')
    turtle.bgcolor('grey')
    turtle.speed(1)

    #### YOUR CODE GOES HERE #################
    #UPPER LEFT


    #upper_left_box
    def upper_left_black():
        turtle.penup()
        
        turtle.fillcolor("Black")
        turtle.begin_fill()
        turtle.pendown()
        for upper_left in range(4):
            turtle.forward(20)
            turtle.left(90)
        turtle.end_fill()
        
        turtle.fillcolor("white")
        turtle.begin_fill()
        turtle.penup()
        turtle.forward(20)
        turtle.pendown()
        for i in range(4):
            turtle.forward(20)
            turtle.left(90)
        turtle.end_fill()
        
        turtle.penup()
        turtle.forward(20)
        turtle.pendown()
    upper_left_black()
    upper_left_black()
    upper_left_black()
    upper_left_black()
    # Example usage of a function from the Lab2_functions module
    #Lab2_functions.()

    ##########################################

if __name__ == "__main__":
    main()
    turtle.done()  # Finish drawing (optional)

    
    
