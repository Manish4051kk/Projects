import turtle

# Draw a line from (x1, y1) to (x2, y2)
# Make line color
def draw_line(x1, y1, x2, y2, color):
    # Save current location and state
    # current_position = turtle.pos()
    pen_state = turtle.pen()
    # Draw line
    turtle.pencolor(color)
    turtle.up()
    turtle.goto(x1, y1)
    turtle.down()
    turtle.goto(x2, y2)
    turtle.up()
    # Reset position, color, and state
    # turtle.goto(current_position)
    turtle.pen(pen_state)

# Draw a draw_rect with the upper left corner at x,y
# and with dimensions x_size by y_size. Use color for
# background
def draw_rect(x, y, x_size, y_size, color):
    # Save current location and state
    # current_position = turtle.pos()
    pen_state = turtle.pen()
    # Set rectangle colors
    turtle.fillcolor(color)
    turtle.pencolor(color)
    # Move Turtle to x,y without drawing a line
    turtle.up()
    turtle.goto(x, y)
    # Draw the rectangle and fill it
    turtle.down()
    turtle.setheading(90)
    turtle.begin_fill()
    turtle.forward(x_size)
    turtle.right(90)
    turtle.forward(y_size)
    turtle.right(90)
    turtle.forward(x_size)
    turtle.right(90)
    turtle.forward(y_size)
    turtle.end_fill()
    turtle.up()
    
    # Reset position, color, and state
    # turtle.goto(current_position)
    turtle.pen(pen_state)


##    turtle.speed(1)  # Set the drawing speed (optional)
##    draw_line(0, 0, 100, 100, "blue")
##    draw_rect(-50, -50, 100, 100, "red")
##    turtle.done()  # Finish drawing (optional)


    
