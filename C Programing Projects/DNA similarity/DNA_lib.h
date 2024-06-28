#ifndef DNA_LIB_H
#define DNA_LIB_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define DNA_SEQ_LEN 50
#define DEFAULT_SHIFTS 10
#define SEQ_1 1
#define SEQ_2 2
#define NO_SHIFT 0

extern const char* NUCLEOTIDES;

void initializeRandom();
char getChoiceYN();
int getNucleotide(int length);
void getDNASequence(char* sequence, int length);
int getShifts();
int getScoreShifted(const char* shift_seq, int shift_index, const char* baseline_seq, int length);
int getSimilarityScore(const char* seq1, const char* seq2, int* max_shifts, int* shifted_seq, int num_shifts);

#endif /* DNA_LIB_H */
