# Building Python Programs
# Programming Project Chapter 6 Gerrymandering

# This program prompts the user for a state name and then outputs a chart 
# displaying the population of democrats and republicans in each district in 
# the state and whether or not that district is gerrymandered. If the user
# types in a state name that doesn't exist the program outputs a not found 
# message.

import turtle
from Lab5_functions import draw_line, draw_rect

WIDTH = 500
HEIGHT = 500

def main():
    turtle.setworldcoordinates(0, HEIGHT, WIDTH, 0)
    turtle.clear()
    turtle.shape('turtle')
    turtle.pencolor('Black')
    turtle.fillcolor('Black')
    turtle.bgcolor('White')

    print_intro_message()
    draw_intro_graphics("Arizona","4738332")
    draw_district_graphics(40,50,5)

    #### YOUR CODE GOES HERE #################
    #### Note - YOU CAN USE THE BELOW TEMPLATE or 
    #### YOU CAN WRITE YOU OWN CUSTOM FUNCTIONS ######

    # take state input
    
    # check if state exists or not

    # if exists, gather the total counts of dem, 
    # gop votes of all districts of the states

    # if not, print state not found


# function to output the introduction message to console.
def print_intro_message():
    print("This program allows you to search through")
    print("data about congressional voting districts")
    print("and determine whether a particular state is")
    print("gerrymandered.\n")

# function to print state name, eligible voters and 
# horizontal and vertical lines to panel
def draw_intro_graphics(state_name, eligible_voters):
    turtle.penup()
    turtle.goto(0,10)
    turtle.pendown()
    turtle.write(state_name)
    turtle.penup()
    turtle.goto(WIDTH-120,10)
    turtle.pendown()
    turtle.write(eligible_voters +" eligible voters")
    draw_line(0,10,WIDTH,10,'Black')
    turtle.penup()
    turtle.goto(250,0)
    turtle.pendown()
    draw_line(250,0,250,WIDTH,'Black')

# function to check whether state exists or not
# if exits, returns the state details line
def get_state_details(file_name, state_name):
    # get a file handle for the requested file. This may error if the file isn't foud, which is ok
    file_handle = open(file_name)
    
    # loop through all lines in the file
    for line in file_handle.readlines():
        # make the line lowercase for comparison's sake
        line_compare = line.lower()
        # check if the lowered line matches with the state we are searching for, also lowered
        if line_compare.startswith(state_name.lower()):
            # if it matches, return the entire unedited line
            return line
    # if no matches are made, return None
    return None

# function to process the state details in the format:
# <state>,<district1>,<dem votes>,<gop votes>,<district2>,<dem votes>,<gop votes>,...
# calculate and return total dem and gop votes
# also prints the district graphics to the panel
def process_state_details(state_details):
    # Split the details line at the commas
    state_details = state_details.split(',')

    # Extract the state name and remove it from the list
    state_name = state_details[0]
    state_details.pop(0)

    # Initialize the total vote variables
    total_democratic_votes = 0
    total_republican_votes = 0

    # Loop through each part of the state details list
    for list_index in range(0, len(state_details), 3):
        # Extract the district name
        district_name = state_details[list_index]
        # Extract the democratic and republic votes
        democratic_votes = int(state_details[list_index + 1])
        republican_votes = int(state_details[list_index + 2])

        # Add the district votes to the total state votes
        total_democratic_votes += democratic_votes
        total_republican_votes += republican_votes

        # Draw the district graph for that district
        draw_district_graphics(democratic_votes, republican_votes, list_index/3)

    # Return the total democratic and republic votes as a list
    return [total_democratic_votes, total_republican_votes]

# function which caluculate the width of dem_votes and gop_votes
# and print the rectangles to the panel using the y_index as starting point
def draw_district_graphics(dem_votes, gop_votes, y_index):
    turtle.penup()
    turtle.goto(0,25)
    turtle.fillcolor("black")
    turtle.begin_fill()
    turtle.pendown()
    total_votes = dem_votes + gop_votes
    # Draw the democratic part of the bar
    turtle.color("blue")
    turtle.begin_fill()
    turtle.forward(dem_votes / total_votes * WIDTH)
    turtle.left(90)
    turtle.forward(20)
    turtle.left(90)
    turtle.forward(dem_votes / total_votes * WIDTH)
    turtle.left(90)
    turtle.end_fill()
    turtle.penup()
    turtle.goto(dem_votes / total_votes * WIDTH,25)
    turtle.pendown()

    # Draw the republican part of the bar
    turtle.color("red")
    turtle.begin_fill()
    turtle.left(90)
    turtle.forward(gop_votes / total_votes * WIDTH)
    turtle.left(90)
    turtle.forward(20)
    turtle.left(90)
    turtle.forward(gop_votes / total_votes * WIDTH)
    turtle.left(90)
    turtle.end_fill()

    
    
    
    
# function to check whether the votes are gerrymandered or not
# and prints out a message if the state is gerrymandered.
# If it is, prints out who has gerrymandered it
def is_gerrymandered(dem_votes, gop_votes):
    wastage = calculate_wastage(dem_votes, gop_votes)
    dem_waste = wastage[0]
    gop_waste = wastage[1]

    wastage_ratio = dem_waste / gop_waste

    waste_beneficiary = None

    if wastage_ratio >= 1.07:
        # dem wastage, gerrymandered for gop
        waste_beneficiary = "Republicans"
    elif wastage_ratio <= (1 / 1.07):
        # gop wastage, gerrymandered for dem
        waste_beneficiary = "Democrats"

    if waste_beneficiary != None:
        print(f"Gerrymandered benefitting the {waste_beneficiary}")

# takes the total number of dem votes and total number of gop
# votes as parameters and calculates and returns the
# total wasted dem votes and total wasted gop votes
def calculate_wastage(dem, gop):
    # get the highest and lowest value of the two voting groups
    highest = max(dem, gop)
    lowest = min(dem, gop)

    # initialize the waste variables
    wasted_dem = 0
    wasted_gop = 0

    # calculate the waste on the high end
    wasted_highest = int((highest - lowest + 1) / 2)

    # check which variable is which, then record the waste properly
    if lowest == dem:
        wasted_dem = lowest
        wasted_gop = wasted_highest
    else:
        wasted_dem = wasted_highest
        wasted_gop = lowest

    # return the waste as a list
    return [wasted_dem, wasted_gop]

main()
