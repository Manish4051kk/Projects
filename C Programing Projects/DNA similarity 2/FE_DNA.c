// Includes the custom DNA library
#include "DNA_lib.h" 

//main program
int main() {
	// Initialize the random number generator
    initializeRandom(); 
	
	// Print the program title
    printf("DNA Similarity Score Calculator\n===============================\n"); 
    
    char repeat = 'y'; // Variable to control if the user wants to repeat
    
    while (repeat == 'y') { // Loop to allow multiple calculations
        // Generate two random DNA sequences of defined length
        char* sequence1 = getDNASequence(DNA_SEQ_LEN); // First DNA sequence
        char* sequence2 = getDNASequence(DNA_SEQ_LEN); // Second DNA sequence

        // Print the generated sequences
        printf("Sequence 1: %s\n", sequence1); 
        printf("Sequence 2: %s\n", sequence2);

        // Clear the input buffer to ensure clean input
        fflush(stdin); // Clear any leftover characters from previous inputs

        // Get the number of shifts from the user
        printf("How many shifts would you like to try (hit enter for default)? "); // Prompt for user input
        int numShifts = getShifts(); // Get the number of shifts
        
        printf("\n"); // Newline for separation of prompt and output
        
        // Calculate the DNA similarity score with the given number of shifts
        int maxShifts;
        int shiftedSequence;
        int chainStartIndex;
        
        // Get the similarity score and related information
        int similarityScore = getSimilarityScore(sequence1, sequence2, numShifts, &maxShifts, &shiftedSequence, &chainStartIndex);

        // Determine which sequence must be shifted and by how much to achieve the best alignment
        if (shiftedSequence == NO_SHIFT) { // No shift yields the maximum score
            printf("Similarity Score: %d\nNo shift results in the maximum alignment score.\n", similarityScore);
        } else { // A shift yields the maximum score
            printf("Similarity Score: %d\nThe maximum alignment score is obtained by shifting Sequence %d by %d shift(s).\n", 
                similarityScore, shiftedSequence, maxShifts);
        }

        // Determine the contiguous chain of matching nucleotides
        printf("Maximum contiguous chain: %.*s\n", 
            similarityScore, // Length of the contiguous chain
            (shiftedSequence == SEQ_1) ? sequence1 + chainStartIndex : sequence2 + chainStartIndex); // Starting position for the contiguous chain
        
        // Ask if the user wants to generate new sequences and repeat
        printf("Generate new sequences [y|n]? "); // Prompt for user input
        repeat = getChoiceYN(); // Get the user's choice
        
        // Free memory for the first and second sequence
        free(sequence1); 
        free(sequence2); 
    }
    
    printf("Program ended.\n"); // Message for ending the program
    
	//return success
    return 0; 
}
