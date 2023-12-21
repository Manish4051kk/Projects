##import random
##def roll_die():
##    return random.randint(1, 6)
##
##def piglet_game():
##    total_score = 0
##    print("Welcome to Piglet!")
##    while True:
##        roll = roll_die()
##        print(f"You rolled a {roll}")
##        if roll == 1:
##            print("You got 0 points")
##            break
##        else:
##            total_score += roll
##        choice = input("Roll again? ")
##        if choice != "y" and choice != "yes":
##            print(f"You got {total_score} points.")
##            break
##
##def main():
##    piglet_game()
##
##main()
##
##
word = "a"
while len(word) < 10:
    word = "b" + word + "b"
print(word)
