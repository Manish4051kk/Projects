import turtle as t
import Lab2_functions  # Import your custom module

# set mortar joints between rows
MORTAR = 2

def main():
    
    t.setworldcoordinates(0, 400, 650, 0)
    t.clear()
    t.shape('turtle')
    t.color('olive drab')
    t.fillcolor("sienna")
    t.bgcolor('grey')
    t.speed(1)

    #### YOUR CODE GOES HERE #################
    t.penup()
    t.goto(120,120)
    t.fillcolor("yellow")
    t.begin_fill()
    t.pendown()
        
    #triangle
    for triangle in range(0,MORTAR+1):          
            t.forward(120)
            t.right(120)
    t.end_fill()
    
    #Square
    t.penup()
    t.goto(350,200)
    t.fillcolor("blue")
    t.begin_fill()
    t.pendown()

    for square in range(0,MORTAR+2):
        t.forward(150)
        t.left(90)
    t.end_fill()

    #Circle
    t.penup()
    t.goto(100,300)
    t.color("Black","Magenta")
    t.pendown()
    t.begin_fill()

    t.circle(50)

    t.end_fill()
    

    

    t.hideturtle()


        
    # Example usage of a function from the Lab2_functions module
    #Lab2_functions.some_function()

    ##########################################

if __name__ == "__main__":
    main()
    t.done()  # Finish drawing (optional)

    
    
