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

    turtle.speed(0)  # Set the turtles speed to the fastest.

    # Function that takes some values and draws an x shape on the squares.

    def draw_blue_x(x1, y1, x2, y2, color):
        Lab2_functions.draw_line(x1, y1, x2, y2, color)

    # Function that takes some values and draws a row of squares.

    def draw_row(num_pairs, size, x_pos, y_pos):
        size_db = size * 2
        for rows in range(0, 1):

            for even_row_blacks in range(0, num_pairs):
                Lab2_functions.draw_rect((even_row_blacks * size_db) + x_pos,   # X position of shape
                                         y_pos + (rows * size_db) + ((MORTAR * rows) * MORTAR),  # Y position of shape
                                         size, size, 'black')  # Size and color of shape
                draw_blue_x(turtle.xcor(), turtle.ycor(), turtle.xcor() + size, turtle.ycor() + size, "blue")  # Draw line one of blue x
                draw_blue_x(turtle.xcor(), turtle.ycor() - size, turtle.xcor() - size, turtle.ycor(), "blue")  # Draw line two of blue x
                for even_row_whites in range(1):
                    Lab2_functions.draw_rect((even_row_blacks * size_db) + x_pos + size,  # X position of shape
                                             y_pos + (rows * size_db) + ((MORTAR * rows) * MORTAR),  # Y position of shape
                                             size, size, 'white')  # Size and color of shape

    # Function that takes some values and outputs a grid of squares.

    def draw_grid(num_pairs, offset, size, x_pos, y_pos):
        size_db = size * 2
        for grids in range(0, num_pairs):

            for even_row_blacks in range(0, num_pairs):  # Draw the rows that are not offset
                Lab2_functions.draw_rect((even_row_blacks * size_db) + x_pos,  # X position of shape
                                         y_pos + (grids * size_db) + (grids * MORTAR * 2),  # Y position of shape
                                         size, size, 'black')  # Size and color of shape
                draw_blue_x(turtle.xcor(), turtle.ycor(), turtle.xcor() + size, turtle.ycor() + size, "blue")  # Draw line one of blue x
                draw_blue_x(turtle.xcor(), turtle.ycor() - size, turtle.xcor() - size, turtle.ycor(), "blue")  # Draw line two of blue x

                for even_row_whites in range(1):
                    Lab2_functions.draw_rect((even_row_blacks * size_db) + x_pos + size,  # X position of shape
                                             y_pos + (grids * size_db) + (grids * MORTAR * 2),  # Y position of shape
                                             size, size, 'white')  # Size and color of shape

            for odd_row_blacks in range(0, num_pairs):  # Draw the rows that are offset
                Lab2_functions.draw_rect((odd_row_blacks * size_db) + x_pos + offset,  # X position of shape
                                         y_pos + size + (grids * size_db) + (2 * (MORTAR * grids) + MORTAR),  # Y position of shape
                                         size, size, 'black')  # Size and color of shape
                draw_blue_x(turtle.xcor(), turtle.ycor(), turtle.xcor() + size, turtle.ycor() + size, "blue")  # Draw line one of blue x
                draw_blue_x(turtle.xcor(), turtle.ycor() - size, turtle.xcor() - size, turtle.ycor(), "blue")  # Draw line two of blue x
                for odd_row_whites in range(1):
                    Lab2_functions.draw_rect((odd_row_blacks * size_db) + x_pos + size + offset,  # X position of shape
                                             y_pos + size + (grids * size_db) + (2 * (MORTAR * grids) + MORTAR),  # Y position of shape
                                             size, size, 'white')  # Size and color of shape

    # For draw_row input: number of pairs, size of square, initial x position, and initial y position
    draw_row(4, 20, 0, 0)  # Draws upper left row
    draw_row(5, 30, 50, 70)  # Draws middle left row
    # For draw_grid input: number of pairs, offset of odd numbered rows, size of squares, initial x position, and initial y position
    draw_grid(4, 0, 25, 10, 150)  # Draws lower left grid
    draw_grid(3, 10, 25, 250, 200)  # Draws lower middle grid
    draw_grid(2, 35, 35, 400, 20)  # Draw upper right grid
    draw_grid(5, 10, 20, 425, 180)  # Draws lower right grid
    turtle.hideturtle()  # Hide the turtle after drawing


if __name__ == "__main__":
    main()
    turtle.done()  # Finish drawing (optional)
