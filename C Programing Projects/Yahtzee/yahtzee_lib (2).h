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
void initializePlayer();

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
char getChoice();

/**
 * Name: rollDice
 * Process: rolls a dice by generating a random number between 1 and 6.
 * Function input/parameters: none
 * Function output/parameters: none
 * Function output/returned: a number between 1 and 6.
 * Dependencies: stdlib.h - rand
 **/
int rollDice();

/**
 * Name: countNumber
 * Process: given an array of dice, this function counts how many dice contains
 *          the numbers from 1-6 (inclusive) and store the result in the output
 *          array of counts.
 * Function input/parameters:
 * 			dice - an array of dice of size NUM_DICE
 * Function output/parameters:
 *          counts - an array of counts of size NUM_SIDE, where each position 
 *          	has the number of times each dice's face was rolled.
 * Function output/returned: none
 * Dependencies: none
 **/
void countNumber(const int dice[], int counts[]);

/**
 * Name: isYahtzee
 * Process: given an array of dice, checks if the numbers in the dice forms a
 * 			Yahtzee.
 * Function input/parameters: dice - an array of dice of size NUM_DICE
 * Function output/parameters: none
 * Function output/returned: true if all the dice has the same number;
 * 							 false otherwise.
 * Dependencies: none
 **/
bool isYahtzee(const int dice[]);

/**
 * Name: isFourOfAKind
 * Process: given the counts for each number found in the dice, check if the
 * 			numbers in the dice forms a Four of a Kind.
 * Function input/parameters:
 * 			counts - an array with the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if four dice show one number and one dice 
 * 			shows another number; false otherwise.
 * Dependencies: none
 **/
bool isFourOfAKind(const int counts[]);

/**
 * Name: hasTwoEqual
 * Process: given the counts for each number found in the dice, check if at
 * 			least one of the counts is equal to 2.
 * Function input/parameters:
 * 			counts - an array with the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if there is at least one of the counts is
 * 			equal to 2; false otherwise.
 * Dependencies: none
 **/
bool hasTwoEqual(const int counts[]);

/**
 * Name: hasThreeEqual
 * Process: given the counts for each number found in the dice, check if at
 * 			least one of the counts is equal to 3.
 * Function input/parameters:
 * 			counts - an array with the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if there is at least one of the counts is
 * 			equal to 3; false otherwise.
 * Dependencies: none
 **/
bool hasThreeEqual(const int counts[]);

/**
 * Name: isThreeOfAKind
 * Process: given the counts for each number found in the dice, check if the
 * 			numbers in the dice forms a Three of a Kind.
 * Function input/parameters:
 * 			counts - an array with the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if three dice show one number and two dice 
 * 			show two other (distinct) numbers; false otherwise.
 * Dependencies: yahtzee_lib.h - hasTwoEqual, hasThreeEqual
 **/
bool isThreeOfAKind(const int counts[]);

/**
 * Name: isFullHouse
 * Process: given the counts for each number found in the dice, check if the
 * 			numbers in the dice forms a Full House.
 * Function input/parameters:
 * 			counts - an array with the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if three dice show one number and two dice 
 * 			shows another number; false otherwise.
 * Dependencies: yahtzee_lib.h - hasTwoEqual, hasThreeEqual
 **/
bool isFullHouse(const int counts[]);

/**
 * Name: isLargeStraight
 * Process: given the counts for each number found in the dice, check if the
 * 			numbers in the dice forms a Large Straight.
 * Function input/parameters:
 * 			counts - an array with the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if there is a sequence of five consecutive
 * 			numbers on the dice; false otherwise.
 * Dependencies: none
 **/
bool isLargeStraight(const int counts[]);

/**
 * Name: isSmallStraight
 * Process: given the counts for each number found in the dice, check if the
 * 			numbers in the dice forms a Small Straight.
 * Function input/parameters:
 * 			counts - an array with the counts for each number found in the dice
 * Function output/parameters: none
 * Function output/returned: true if there is a sequence of four consecutive
 * 			numbers on the dice; false otherwise.
 * Dependencies: none
 **/
bool isSmallStraight(const int counts[]);

/**
 * Name: decidePlay
 * Process: given an array of dice, checks wich of the plays was achieved,
 * 			if any.
 * Function input/parameters: dice - an array of dice of size NUM_DICE
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
int decidePlay(const int dice[]);

#endif