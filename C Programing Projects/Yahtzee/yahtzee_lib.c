#ifndef YAHTZEE_LIB_H
#define YAHTZEE_LIB_H

// header files
#include <stdio.h>
#include <stdlib.h> // for rand, srand
#include <time.h> // for time
#include <ctype.h> // for tolower
#include <stdbool.h> // for bool data type

// global constants
#define NUM_DICE 5
#define NUM_SIDES 6
#define NO_PLAY 0
#define YAHTZEE 1
#define L_STRAIGHT 2
#define S_STRAIGHT 3
#define FULL_HOUSE 4
#define FOUR_OF_A_KIND 5
#define THREE_OF_A_KIND 6

/**
 * Name: initializePlayer
 * Process: initialize the random number generator
 * Function input/parameters: none
 * Function output/parameters: none
 * Function output/returned: none
 * Dependencies: stdlib.h - srand
 * 				 time.h - time
 **/
void initializePlayer() {
    srand(time(NULL));
}

/**
 * Name: getChoice
 * Process: reads and validates a lowercase character input, ensuring it is
 * 			either 'y' or 'n'
 * Function input/parameters: none
 * Function output/parameters: none
 * Function output/returned: the read char value (either 'n' or 'y')
 * Dependencies: stdio.h - scanf, printf
 * 				 ctype.h - tolower
 **/
char getChoice() {
    char choice;
    scanf(" %c", &choice);
    return tolower(choice);
}

/**
 * Name: rollDice
 * Process: rolls a dice by generating a random number between 1 and 6.
 * Function input/parameters: none
 * Function output/parameters: none
 * Function output/returned: a number between 1 and 6.
 * Dependencies: stdlib.h - rand
 **/
int rollDice() {
    return (rand() % 6) + 1;
}

/**
 * Name: countNumber
 * Process: given an integer number, counts how many dice contains the
 * 			number
 * Function input/parameters:
 * 			number - the number to be found in the dice
 * 			dice1-dice5 - the dice
 * Function output/parameters: none
 * Function output/returned:
 * 			count - an integer number that represents how many dice contains
 * 				the number in the input variable number
 * Dependencies: none
 **/
int countNumber(int number, int dice1, int dice2, int dice3, int dice4, int dice5) {
    int count = 0;
    if (dice1 == number) count++;
    if (dice2 == number) count++;
    if (dice3 == number) count++;
    if (dice4 == number) count++;
    if (dice5 == number) count++;
    return count;
}

/**
 * Name: isYahtzee
 * Process: given the five dice, checks if the numbers in the dice forms a
 * 			Yahtzee.
 * Function input/parameters: dice1-dice5 - the dice
 * Function output/parameters: none
 * Function output/returned: true if all the dice has the same number;
 * 							 false otherwise.
 * Dependencies: none
 **/
bool isYahtzee(int dice1, int dice2, int dice3, int dice4, int dice5) {
    return (dice1 == dice2 && dice2 == dice3 && dice3 == dice4 && dice4 == dice5);
}

/**
 * Name: isFourOfAKind
 * Process: given the counts for each number found in the dice, check if the
 * 			numbers in the dice forms a Four of a Kind.
 * Function input/parameters:
 * 			count1-count6 - the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if four dice show one number and one dice 
 * 			shows another number; false otherwise.
 * Dependencies: none
 **/
bool isFourOfAKind(int count1, int count2, int count3, int count4, int count5, int count6) {
    return (count1 >= 4 || count2 >= 4 || count3 >= 4 || count4 >= 4 || count5 >= 4 || count6 >= 4);
}

/**
 * Name: hasTwoEqual
 * Process: given the counts for each number found in the dice, check if at
 * 			least one of the counts is equal to 2.
 * Function input/parameters:
 * 			count1-count6 - the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if there is at least one of the counts is
 * 			equal to 2; false otherwise.
 * Dependencies: none
 **/
bool hasTwoEqual(int count1, int count2, int count3, int count4, int count5, int count6) {
    return (count1 == 2 || count2 == 2 || count3 == 2 || count4 == 2 || count5 == 2 || count6 == 2);
}

/**
 * Name: hasThreeEqual
 * Process: given the counts for each number found in the dice, check if at
 * 			least one of the counts is equal to 3.
 * Function input/parameters:
 * 			count1-count6 - the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if there is at least one of the counts is
 * 			equal to 3; false otherwise.
 * Dependencies: none
 **/
bool hasThreeEqual(int count1, int count2, int count3, int count4, int count5, int count6) {
    return (count1 == 3 || count2 == 3 || count3 == 3 || count4 == 3 || count5 == 3 || count6 == 3);
}

/**
 * Name: isThreeOfAKind
 * Process: given the counts for each number found in the dice, check if the
 * 			numbers in the dice forms a Three of a Kind.
 * Function input/parameters:
 * 			count1-count6 - the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if three dice show one number and two dice 
 * 			show two other (distinct) numbers; false otherwise.
 * Dependencies: yahtzee_lib.h - hasTwoEqual, hasThreeEqual
 **/
bool isThreeOfAKind(int count1, int count2, int count3, int count4, int count5, int count6) {
    return hasThreeEqual(count1, count2, count3, count4, count5, count6) && !isFourOfAKind(count1, count2, count3, count4, count5, count6);
}

/**
 * Name: isFullHouse
 * Process: given the counts for each number found in the dice, check if the
 * 			numbers in the dice forms a Full House.
 * Function input/parameters:
 * 			count1-count6 - the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if three dice show one number and two dice 
 * 			shows another number; false otherwise.
 * Dependencies: yahtzee_lib.h - hasTwoEqual, hasThreeEqual
 **/
bool isFullHouse(int count1, int count2, int count3, int count4, int count5, int count6) {
    return (hasTwoEqual(count1, count2, count3, count4, count5, count6) && hasThreeEqual(count1, count2, count3, count4, count5, count6));
}

/**
 * Name: isLargeStraight
 * Process: given the counts for each number found in the dice, check if the
 * 			numbers in the dice forms a Large Straight.
 * Function input/parameters:
 * 			count1-count6 - the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if there is a sequence of five consecutive
 * 			numbers on the dice; false otherwise.
 * Dependencies: none
 **/
bool isLargeStraight(int count1, int count2, int count3, int count4, int count5, int count6) {
    return ((count1 == 1 && count2 == 1 && count3 == 1 && count4 == 1 && count5 == 1) || (count2 == 1 && count3 == 1 && count4 == 1 && count5 == 1 && count6 == 1));
}

/**
 * Name: isSmallStraight
 * Process: given the counts for each number found in the dice, check if the
 * 			numbers in the dice forms a Small Straight.
 * Function input/parameters:
 * 			count1-count6 - the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if there is a sequence of four consecutive
 * 			numbers on the dice; false otherwise.
 * Dependencies: none
 **/
bool isSmallStraight(int count1, int count2, int count3, int count4, int count5, int count6) {
    return ((count1 >= 1 && count2 >= 1 && count3 >= 1 && count4 >= 1) || (count2 >= 1 && count3 >= 1 && count4 >= 1 && count5 >= 1) || (count3 >= 1 && count4 >= 1 && count5 >= 1 && count6 >= 1));
}

/**
 * Name: decidePlay
 * Process: given the five dice, checks wich of the plays was achieved, if any.
 * Function input/parameters: dice1-dice5 - the dice
 * Function output/parameters: none
 * Function output/returned:
 * 		the constant YAHTZEE: if the dice is forms a Yahtzee;
 * 		the constant FULL_HOUSE: if the dice is forms a full house;
 * 		the constant THREE_OF_A_KIND: if the dice is forms a three of a kind;
 * 		the constant FOUR_OF_A_KIND: if the dice is forms a four of a kind;
 * 		the constant S_STRAIGHT: if the dice is forms a small straight;
 * 		the constant L_STRAIGHT: if the dice is forms a large straight;
 * 		the constant NO_PLAY: if none of the above;
 * Dependencies: yahtzee_lib.h - isYahtzee, countNumber, isFourOfAKind, 
 * 			isThreeOfAKind, isFullHouse, isLargeStraight, isSmallStraight
 **/
int decidePlay(int dice1, int dice2, int dice3, int dice4, int dice5) {
    int count1 = countNumber(1, dice1, dice2, dice3, dice4, dice5);
    int count2 = countNumber(2, dice1, dice2, dice3, dice4, dice5);
    int count3 = countNumber(3, dice1, dice2, dice3, dice4, dice5);
    int count4 = countNumber(4, dice1, dice2, dice3, dice4, dice5);
    int count5 = countNumber(5, dice1, dice2, dice3, dice4, dice5);
    int count6 = countNumber(6, dice1, dice2, dice3, dice4, dice5);
    
    if (isYahtzee(dice1, dice2, dice3, dice4, dice5))
        return YAHTZEE;
    else if (isFullHouse(count1, count2, count3, count4, count5, count6))
        return FULL_HOUSE;
    else if (isThreeOfAKind(count1, count2, count3, count4, count5, count6))
        return THREE_OF_A_KIND;
    else if (isFourOfAKind(count1, count2, count3, count4, count5, count6))
        return FOUR_OF_A_KIND;
    else if (isLargeStraight(count1, count2, count3, count4, count5, count6))
        return L_STRAIGHT;
    else if (isSmallStraight(count1, count2, count3, count4, count5, count6))
        return S_STRAIGHT;
    else
        return NO_PLAY;

}

#endif