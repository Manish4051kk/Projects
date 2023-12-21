import turtle
import sys
import keyboard

# Constants
DEFAULT_SCREEN_WIDTH = 1000
DEFAULT_SCREEN_HEIGHT = 1000

# Initialize the turtle screen
screen_width = int(sys.argv[1]) if len(sys.argv) > 1 else DEFAULT_SCREEN_WIDTH
screen_height = int(sys.argv[2]) if len(sys.argv) > 2 else DEFAULT_SCREEN_HEIGHT
turtle.setup(width=screen_width, height=screen_height)
turtle.bgcolor("white")

# Create the turtle pen
pen = turtle.Turtle()
pen.shape("turtle")
pen.color("black")
pen.speed(0)
pen.penup()
pen.goto(0, 0)
pen.setheading(0)  # Start in the right direction
pen.pendown()

# Variable to control pen movement
pen_moving = False

# Function to move the pen continuously
def move_pen():
    global pen_moving
    if pen_moving:
        pen.forward(10)
        # Teleport if hitting the window boundaries
        x, y = pen.xcor(), pen.ycor()
        if x > screen_width // 2:
            teleport(-screen_width // 2, y)
        elif x < -screen_width // 2:
            teleport(screen_width // 2, y)
        elif y > screen_height // 2:
            teleport(x, -screen_height // 2)
        elif y < -screen_height // 2:
            teleport(x, screen_height // 2)
    turtle.ontimer(move_pen, 10)  # Call move_pen every 10 milliseconds

# Function to handle key presses
def handle_key_event(event):
    global pen_moving
    key = event.name
    if event.event_type == keyboard.KEY_DOWN:
        if key == 'p':
            if pen.isdown():
                pen.penup()
            else:
                pen.pendown()
        else:
            if key == 'w':
                pen_moving = True
                pen.setheading(90)
            elif key == 's':
                pen_moving = True
                pen.setheading(270)
            elif key == 'a':
                pen_moving = True
                pen.setheading(180)
            elif key == 'd':
                pen_moving = True
                pen.setheading(0)
            elif key == 'q':
                turtle.Screen().bye()

# Function to teleport the pen to a specific position
def teleport(x, y):
    pen.penup()
    pen.goto(x, y)
    pen.pendown()

# Keyboard bindings using the keyboard module
keyboard.hook(handle_key_event)

# Start the pen movement loop
move_pen()

# Keep the program running
turtle.mainloop()
