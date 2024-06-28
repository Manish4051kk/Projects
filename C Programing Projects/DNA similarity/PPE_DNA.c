#include <stdio.h>
#include "DNA_lib.h"

int main() {
    printf("DNA Similarity Score Calculator\n");
    printf("===============================\n\n");

    char sequence1[DNA_SEQ_LEN];
    char sequence2[DNA_SEQ_LEN];
    int max_shifts;
    int shifted_seq;
    char choice;

    do {
        printf("Sequence 1: ");
        getDNASequence(sequence1, DNA_SEQ_LEN);
        printf("%s\n", sequence1);

        printf("Sequence 2: ");
        getDNASequence(sequence2, DNA_SEQ_LEN);
        printf("%s\n\n", sequence2);

        max_shifts = getShifts();
        printf("Calculating the DNA Similarity Score using a maximum of %d shifts...\n\n", max_shifts);

        int similarity_score = getSimilarityScore(sequence1, sequence2, &max_shifts, &shifted_seq, max_shifts);

        printf("Similarity Score: %d\n", similarity_score);
        if (shifted_seq == NO_SHIFT) {
            printf("No shift results in the maximum alignment score.\n");
        } else {
            printf("The maximum alignment score is obtained by shifting ");
            if (shifted_seq == SEQ_1) {
                printf("Sequence 1 by %d shifts.\n", max_shifts);
            } else if (shifted_seq == SEQ_2) {
                printf("Sequence 2 by %d shifts.\n", max_shifts);
            }
        }

        printf("\nGenerate new sequences [y|n]? ");
        choice = getChoiceYN();
    } while (choice == 'y');

    printf("Program ended.\n");

    return 0;
}
