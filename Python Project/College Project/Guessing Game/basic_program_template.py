# imported libraries
import random
import math

# Constants
MAX_NUMBER = 100

# The main program
# ----------------
def main():
    intro_message()
    print()
    print(f"I'm thinking of a number between 1 and {MAX_NUMBER}...")

    play_a_game()
    
    


    pass

# Supporting functions (in alphabetical order)
# --------------------------------------------
def intro_message():
#haiku message for the user
    print("The code's silent dance,\nGuessing a game, take a chance,\nPython's magic, advance.")
    

# A function that plays one game
def play_a_game():
    number = random.randint(1, MAX_NUMBER)
    count_1 = 1
    while True:
        guess = int(input("Your guess: "))
        if guess < number:
            print("It's lower.")
        elif guess > number:
            print("It's higher.")
        elif guess == number:
            print("You guessed it in " + str(count_1) + " tries.")
            play_again = input("Do you want to play again? ")
    # A sentinel loop to keep playing after each game is done
            if play_again == "y" or play_again == "YES":
                print()
                print(f"I'm thinking of a number between 1 and {MAX_NUMBER}...")
                play_a_game()
            elif play_again == "no":
                print()
                statistics()

            return
        count_1 +=1

            
           



    # Required return: number of guesses
    # Device input: number guesses
    # Device output: prompts and number of guesses required



# A function that displays
def statistics():
    print("Overall results:")
    total_game = print(f"Total games   = {count_1}")
    # Required input (parameters): game tallies
    # Required return: none
    # Device input: none
    # Device output: overall results table
    

main()
