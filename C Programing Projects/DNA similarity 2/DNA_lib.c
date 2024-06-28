#include "DNA_lib.h" // Includes the DNA library header file

const char* NUCLEOTIDES = "AGCT"; // Defining the available nucleotides

// Function: initializeRandom
// Process: Initializes the random number generator with the current system time for reproducible randomness.
// Function input/parameters: None.
// Function output/parameters: None.
// Function output/returned: None.
// Dependencies: time.h - time; stdlib.h - srand.
void initializeRandom() {
    srand((unsigned int)time(NULL)); // Seeds the random generator with the current time
}

// Function: getChoiceYN
// Process: Reads a single character from the standard input and checks if it is 'y' or 'n'.
//           If the input is invalid, it prompts the user until a valid input is provided.
// Function input/parameters: None.
// Function output/parameters: None.
// Function output/returned: char: A valid 'y' or 'n' character from user input.
// Dependencies: ctype.h - tolower; stdio.h - getchar, puts.
char getChoiceYN() {
    char choice; // Variable to store user input
    do {
        int c = getchar(); // Read a character from user input
        if (c == '\n' || c == EOF) { // If it's a newline or end-of-file, read again
            continue;
        }
        choice = tolower(c); // Converts the character to lowercase
        if (choice != 'y' && choice != 'n') { // Checks for valid input
            puts("Invalid option. Please type 'y' to repeat or 'n' to exit: "); // Error message for invalid input
        }
    } while (choice != 'y' && choice != 'n'); // Repeats until valid input
    return choice; // Returns valid input
}

// Function: getNucleotide
// Process: Generates a random index within the range of available nucleotides (from 0 to nucleotideLength - 1).
// Function input/parameters: nucleotideLength (int): The length of the NUCLEOTIDES string.
// Function output/parameters: None.
// Function output/returned: int: A random index within the range.
// Dependencies: stdlib.h - rand.
int getNucleotide(int nucleotideLength) {
    return rand() % nucleotideLength; // Returns a random index
}

// Function: getDNASequence
// Process: Allocates memory for a DNA sequence and fills it with random nucleotides from NUCLEOTIDES.
// Function input/parameters: length (int): The length of the DNA sequence to generate.
// Function output/parameters: None.
// Function output/returned: char*: A dynamically allocated null-terminated DNA sequence.
// Dependencies: stdlib.h - calloc, exit; stdio.h - fprintf; string.h - strlen.
char* getDNASequence(int length) {
    char* sequence = calloc(length + 1, sizeof(char)); // Allocates memory for the DNA sequence
    if (sequence == NULL) { // Checks if memory allocation was successful
        fprintf(stderr, "Memory allocation failed.\n"); // Error message if allocation fails
        exit(EXIT_FAILURE); // Exits with a failure status
    }
    for (int i = 0; i < length; i++) { // Fills the sequence with random nucleotides
        int index = getNucleotide(4); // Gets a random index for a nucleotide
        sequence[i] = NUCLEOTIDES[index]; // Assigns the nucleotide to the sequence
    }
    sequence[length] = '\0'; // Null-terminates the DNA sequence
    return sequence; // Returns the generated DNA sequence
}

// Function: getShifts
// Process: Reads the number of shifts from user input, validates it, and returns a valid shift count.
//           If the user presses Enter without input, it returns the default shift count.
// Function input/parameters: None.
// Function output/parameters: None.
// Function output/returned: int: A valid number of shifts.
// Dependencies: stdio.h - fgets, puts; stdlib.h - atoi.
int getShifts() {
    char value[3]; // Buffer to store the user input
    fgets(value, sizeof(value), stdin); // Reads the input from the user
    if (value[0] == '\n') { // Checks if the user hit Enter without providing a value
        return DEFAULT_SHIFTS; // Returns the default number of shifts
    }
    int shifts = atoi(value); // Converts the input to an integer
    if (shifts < 0) { // Checks if the number of shifts is negative
        puts("Invalid option. The number of shifts cannot be negative. Please try again: "); // Error message for negative value
        return getShifts(); // Recursively gets a valid input
    }
    if (shifts > DNA_SEQ_LEN / 2) { // Checks if the number of shifts is greater than half the DNA sequence's length
        puts("Invalid option. The number of shifts cannot be more than half of the DNA sequence's length: "); // Error message for exceeding limit
        return getShifts(); // Recursively gets a valid input
    }
    return shifts; // Returns the valid number of shifts
}

// Function: getScoreShifted
// Process: Calculates the maximum length of contiguous matching nucleotides between a shifted sequence and a baseline sequence.
// Function input/parameters: shiftSeq (const char*): The sequence to shift and compare.
//                            shiftIndex (int): The number of positions to shift the sequence.
//                            baselineSeq (const char*): The baseline sequence for comparison.
//                            length (int): The total length of the sequences.
// Function output/parameters: None.
// Function output/returned: int: The maximum length of contiguous matching nucleotides.
// Dependencies: None.
int getScoreShifted(const char* shiftSeq, int shiftIndex, const char* baselineSeq, int length) {
    int maxChain = 0; // Maximum chain length of contiguous matching nucleotides
    int currentChain = 0; // Current chain length of contiguous matching nucleotides

    // Compares each nucleotide in the shifted sequence with the baseline sequence
    for (int i = 0; i < length - shiftIndex; i++) { 
        if (shiftSeq[shiftIndex + i] == baselineSeq[i]) { // Checks if nucleotides match
            currentChain++; // Increments the current chain length
            if (currentChain > maxChain) { // If the current chain is greater than maxChain
                maxChain = currentChain; // Update maxChain
            }
        } else { // If nucleotides don't match
            currentChain = 0; // Resets the current chain length
        }
    }

    return maxChain; // Returns the maximum chain length
}

// Function: getSimilarityScore
// Process: Calculates the maximum similarity score for two DNA sequences with a possible number of shifts.
//           The function determines the best score when shifting each sequence by various amounts.
// Function input/parameters: seq1 (const char*): First DNA sequence.
//                            seq2 (const char*): Second DNA sequence.
//                            numShifts (int): The maximum number of shifts to consider.
//                            maxShifts (int*): Output parameter to return the best number of shifts.
//                            sequence (int*): Output parameter to return which sequence should be shifted.
//                            chainIndex (int*): Output parameter for the starting index of the maximum contiguous chain.
// Function output/parameters: None.
// Function output/returned: int: The maximum similarity score.
// Dependencies: None.
int getSimilarityScore(const char* seq1, const char* seq2, int numShifts, int* maxShifts, int* sequence, int* chainIndex) {
    int maxScore = getScoreShifted(seq1, 0, seq2, DNA_SEQ_LEN); // Initial score with no shifts
    *sequence = NO_SHIFT; // No sequence is shifted
    *maxShifts = NO_SHIFT; // Default to no shift
    *chainIndex = 0; // Starting index for the chain is 0

    // Checks the alignment score when shifting Sequence 1
    for (int shift = 1; shift <= numShifts; shift++) { 
        int score = getScoreShifted(seq1, shift, seq2, DNA_SEQ_LEN); // Calculates the score with a shift
        if (score > maxScore) { // If the new score is higher than maxScore
            maxScore = score; // Update maxScore
            *maxShifts = shift; // Update maxShifts
            *sequence = SEQ_1; // Indicates that Sequence 1 is the shifted sequence
            *chainIndex = shift; // Starting index for the contiguous chain
        }
    }

    // Checks the alignment score when shifting Sequence 2
    for (int shift = 1; shift <= numShifts; shift++) { 
        int score = getScoreShifted(seq2, shift, seq1, DNA_SEQ_LEN); // Calculates the score with a shift
        if (score > maxScore) { // If the new score is higher than maxScore
            maxScore = score; // Update maxScore
            *maxShifts = shift; // Update maxShifts
            *sequence = SEQ_2; // Indicates that Sequence 2 is the shifted sequence
            *chainIndex = shift; // Starting index for the contiguous chain
        }
    }

    return maxScore; // Returns the maximum similarity score
}
