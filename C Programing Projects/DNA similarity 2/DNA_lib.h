#ifndef DNA_LIB_H
#define DNA_LIB_H

// Including necessary C libraries
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

// Defining global constants
#define DNA_SEQ_LEN 50 // Maximum length for a DNA sequence
#define DEFAULT_SHIFTS 10 // Default number of shifts
#define SEQ_1 1 // Identifier for the first sequence
#define SEQ_2 2 // Identifier for the second sequence
#define NO_SHIFT 0 // Identifier for no shift
extern const char* NUCLEOTIDES; // Available DNA nucleotides

// Function to initialize the random number generator
void initializeRandom();

// Function to get user input for yes/no questions
char getChoiceYN();

// Function to get a random nucleotide index
int getNucleotide(int nucleotideLength);

// Function to generate a random DNA sequence
char* getDNASequence(int length);

// Function to get the number of shifts from the user
int getShifts();

// Function to get the alignment score for shifted sequences
int getScoreShifted(const char* shiftSeq, int shiftIndex, const char* baselineSeq, int length);

// Function to get the similarity score for two DNA sequences
int getSimilarityScore(const char* seq1, const char* seq2, int numShifts, int* maxShifts, int* sequence, int* chainIndex);

#endif // DNA_LIB_H
