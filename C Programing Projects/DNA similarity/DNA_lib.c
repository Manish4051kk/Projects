#include "DNA_lib.h"

const char* NUCLEOTIDES = "AGCT";

void initializeRandom() {
    /* FSPP comments:
     * This function initializes the random number generator based on the current time.
     */
    srand((unsigned int)time(NULL));
}

char getChoiceYN() {
    /* FSPP comments:
     * This function reads a character value from the user input and validates if it's 'y' or 'n'.
     * If not, it prompts the user to try again until a valid input is received.
     * Returns the input character.
     */
    char choice;
    do {
        scanf(" %c", &choice);
        choice = tolower(choice);
        fflush(stdin);
    } while (choice != 'y' && choice != 'n');
    return choice;
}

int getNucleotide(int length) {
    /* FSPP comments:
     * This function generates a random number between 0 and length-1 representing an index of NUCLEOTIDES.
     * Returns the generated random number.
     */
    return rand() % length;
}

void getDNASequence(char* sequence, int length) {
    /* FSPP comments:
     * This function fills in each position of the given DNA sequence with random characters from NUCLEOTIDES.
     * The last position of the DNA sequence is set to the null terminator '\0'.
     */
    for (int i = 0; i < length - 1; i++) {
        sequence[i] = NUCLEOTIDES[getNucleotide(strlen(NUCLEOTIDES))];
    }
    sequence[length - 1] = '\0';
}

int getShifts() {
    /* FSPP comments:
     * This function reads an integer number from the user input and validates its range.
     * If the input is not within the valid range, appropriate error messages are displayed.
     * Returns the valid input number of shifts or DEFAULT_SHIFTS if the user input is empty.
     */
    char value[3];
    int shifts;
    do {
        printf("How many shifts would you like to try (hit enter for default)? ", DNA_SEQ_LEN / 2);
        fgets(value, sizeof(value), stdin);
        fflush(stdin);
        if (value[0] == '\n') {
            return DEFAULT_SHIFTS;
        }
        shifts = atoi(value);
        if (shifts < 0) {
            printf("Invalid option. The number of shifts cannot be negative. Please try again.\n");
        } else if (shifts > DNA_SEQ_LEN / 2) {
            printf("Invalid option. The number of shifts cannot be more than half of the DNA sequence's length.\n");
        }
    } while (shifts < 0 || shifts > DNA_SEQ_LEN / 2);
    return shifts;
}

int getScoreShifted(const char* shift_seq, int shift_index, const char* baseline_seq, int length) {
    /* FSPP comments:
     * This function calculates the alignment score by comparing the nucleotides of two DNA sequences.
     * It iterates through the sequences starting from the specified shift index, counting matching nucleotides.
     * Returns the alignment score.
     */
    int score = 0;
    for (int i = 0; i < length - shift_index; i++) {
        if (shift_seq[shift_index + i] == baseline_seq[i]) {
            score++;
        }
    }
    return score;
}

int getSimilarityScore(const char* seq1, const char* seq2, int* max_shifts, int* shifted_seq, int num_shifts) {
    /* FSPP comments:
     * This function calculates the maximum alignment score between two DNA sequences with possible shifts.
     * It compares both sequences without shifting and then iterates through possible shifts for both sequences
     * to find the maximum alignment score.
     * Updates max_shifts and shifted_seq to store the optimal shift configuration.
     * Returns the maximum alignment score.
     */
    int max_score = 0;
    *max_shifts = NO_SHIFT;
    *shifted_seq = NO_SHIFT;
    
    // Calculate maximum score when sequences are not shifted
    int score_no_shift = getScoreShifted(seq1, 0, seq2, DNA_SEQ_LEN);
    if (score_no_shift > max_score) {
        max_score = score_no_shift;
    }
    
    // Calculate maximum score for all possible shifts of Sequence 1
    for (int i = 1; i <= num_shifts; i++) {
        int score_seq1_shifted = getScoreShifted(seq1, i, seq2, DNA_SEQ_LEN);
        if (score_seq1_shifted > max_score) {
            max_score = score_seq1_shifted;
            *max_shifts = i;
            *shifted_seq = SEQ_1;
        }
    }
    
    // Calculate maximum score for all possible shifts of Sequence 2
    for (int i = 1; i <= num_shifts; i++) {
        int score_seq2_shifted = getScoreShifted(seq2, i, seq1, DNA_SEQ_LEN);
        if (score_seq2_shifted > max_score) {
            max_score = score_seq2_shifted;
            *max_shifts = i;
            *shifted_seq = SEQ_2;
        }
    }
    
    return max_score;
}
