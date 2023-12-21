import random

# Constants
MAX_NUMBER = 100

# The main program
def main():
    #haiku message for the user
    print("The code's silent dance,\nGuessing a game, take a chance,\nPython's magic, advance.")
    Total_games_played = 0
    Guessed_times = 0
# Supporting functions (in alphabetical order)
# --------------------------------------------

    while True:
        print(f"\nI'm thinking of a number between 1 and {MAX_NUMBER}...")
        number = random.randint(1, MAX_NUMBER)
        guesses = play_a_game(number)
        
        Total_games_played += 1
         # Required return: number of guesses
        Guessed_times += guesses
        Best_score = guesses
        # A sentinel loop to keep playing after each game is done
        play_again = input("Do you want to play again? (yes/no): ")
        play_again = play_again[0]
        if play_again != 'y' and play_again != 'Y':
            break

    statistics(Total_games_played,Guessed_times,Best_score)

# A function that plays one game
def play_a_game(number):
    count = 0

    while True:
         # Device input: number guesses
        guess = int(input("Your guess: "))
        if guess > number:
            print("It's lower.")
        elif guess < number:
            print("It's higher.")
        else:
            print("You got it right in", count, "guesses!")
            return count

        count += 1
# A function that displays statistics
def statistics(Total_games_played,Guessed_times,Best_score):
        print()
        print("Overall results:")
            # Device output: prompts and number of guesses required
        print("Total games =", Total_games_played)
        print("Total guesses =", Guessed_times)
        print(f"Guesses/game = {Guessed_times / Total_games_played}")
        print("Best game =", Best_score)


main()
