import turtle
import Lab2_functions  # Import your custom module

# set mortar joints between rows
MORTAR = 2


def main():
    turtle.setworldcoordinates(0, 400, 650, 0)
    turtle.clear()
    turtle.shape('turtle')
    turtle.pencolor('black')
    turtle.fillcolor('black')
    turtle.bgcolor('grey')

    # YOUR CODE GOES HERE #
    # Set the turtles speed to the 1.
    turtle.speed(0)

    # Function that print X inside the black boxes.

    def blue_x(x1, y1, x2, y2, color):
        Lab2_functions.draw_line(x1, y1, x2, y2, color)

    # Function that draw squares in row.

    def square_row(num_pairs, size, x_pos, y_pos):
        size_row = size * 2
        for rows in range(0, 1):

            for even_blacks_box in range(0, num_pairs):
                
                Lab2_functions.draw_rect((even_blacks_box * size_row) + x_pos,   
                                         y_pos + (rows * size_row) + ((MORTAR * rows) * MORTAR),  
                                         size, size, 'black')  # Size and color of the shape
                blue_x(turtle.xcor(), turtle.ycor(), turtle.xcor() + size, turtle.ycor() + size, "blue")  
                blue_x(turtle.xcor(), turtle.ycor() - size, turtle.xcor() - size, turtle.ycor(), "blue")  
                for even_white_row in range(1):
                    Lab2_functions.draw_rect((even_blacks_box * size_row) + x_pos + size,  
                                             y_pos + (rows * size_row) + ((MORTAR * rows) * MORTAR),  
                                             size, size, 'white')  # Size and color of the shape

    # Function that make the grid of squares.

    def grid_square(num_pairs, offset, size, x_pos, y_pos):
        size_row = size * 2
        for grid in range(0, num_pairs):

            for even_blacks_box in range(0, num_pairs):  # Draw the rows that are not offset
                Lab2_functions.draw_rect((even_blacks_box * size_row) + x_pos,  
                                         y_pos + (grid * size_row) + (grid * MORTAR * 2),  
                                         size, size, 'black')  # Size and color of shape
                blue_x(turtle.xcor(), turtle.ycor(), turtle.xcor() + size, turtle.ycor() + size, "blue")  
                blue_x(turtle.xcor(), turtle.ycor() - size, turtle.xcor() - size, turtle.ycor(), "blue")  

                for even_whites_row in range(1):
                    Lab2_functions.draw_rect((even_blacks_box * size_row) + x_pos + size,  
                                             y_pos + (grid * size_row) + (grid * MORTAR * 2),  
                                             size, size, 'white')  # Size and color of shape

            for odd_blacks_box in range(0, num_pairs):  # Draw the rows that are offset
                Lab2_functions.draw_rect((odd_blacks_box * size_row) + x_pos + offset, 
                                         y_pos + size + (grid * size_row) + (2 * (MORTAR * grid) + MORTAR),  
                                         size, size, 'black')  # Size and color of shape
                blue_x(turtle.xcor(), turtle.ycor(), turtle.xcor() + size, turtle.ycor() + size, "blue")  
                blue_x(turtle.xcor(), turtle.ycor() - size, turtle.xcor() - size, turtle.ycor(), "blue")  
                for odd_whites_box in range(1):
                    Lab2_functions.draw_rect((odd_blacks_box * size_row) + x_pos + size + offset,  
                                             y_pos + size + (grid * size_row) + (2 * (MORTAR * grid) + MORTAR), 
                                             size, size, 'white')  # Size and color of shape

    
    square_row(4, 20, 0, 0)  # Draws upper left row
    square_row(5, 30, 50, 70)  # Draws middle left row
    grid_square(4, 0, 25, 10, 150)  # Draws lower left grid
    grid_square(3, 10, 25, 250, 200)  # Draws lower middle grid
    grid_square(2, 35, 35, 400, 20)  # Draw upper right grid
    grid_square(5, 10, 20, 425, 180)  # Draws lower right grid
    
    turtle.hideturtle() 


if __name__ == "__main__":
    main()
    turtle.done()  # Finish drawing (optional)
