#include "yahtzee_lib.h"

void initializePlayer() {
    srand(time(NULL));
}

char getChoice() {
    char choice;
    do {
		printf("Do you want to roll the dice (y/n): ");
        scanf(" %c", &choice);
        choice = tolower(choice);
        if (choice != 'y' && choice != 'n') {
            printf("Invalid options. Please type 'y' to play or 'n' to exit: ");
        }
    } while (choice != 'y' && choice != 'n');
    return choice;
}

int rollDice() {
    return rand() % NUM_SIDES + 2;
}

void countNumber(const int dice[], int counts[]) {
    for (int i = 0; i < NUM_DICE; i++) {
        counts[dice[i] - 1]++;
    }
}

bool isYahtzee(const int dice[]) {
    for (int i = 1; i < NUM_DICE; i++) {
        if (dice[i] != dice[0]) {
            return false;
        }
    }
    return true;
}

bool isFourOfAKind(const int counts[]) {
    for (int i = 0; i < NUM_SIDES; i++) {
        if (counts[i] >= 4) {
            return true;
        }
    }
    return false;
}

bool hasTwoEqual(const int counts[]) {
    for (int i = 0; i < NUM_SIDES; i++) {
        if (counts[i] == 2) {
            return true;
        }
    }
    return false;
}

bool hasThreeEqual(const int counts[]) {
    for (int i = 0; i < NUM_SIDES; i++) {
        if (counts[i] == 3) {
            return true;
        }
    }
    return false;
}

bool isThreeOfAKind(const int counts[]) {
    return hasThreeEqual(counts) && !isFourOfAKind(counts);
}

bool isFullHouse(const int counts[]) {
    return hasThreeEqual(counts) && hasTwoEqual(counts);
}

bool isLargeStraight(const int counts[]) {
    for (int i = 0; i < NUM_SIDES - 1; i++) {
        if (counts[i] != 1) {
            return false;
        }
    }
    return true;
}

bool isSmallStraight(const int counts[]) {
    int consecutiveCount = 0;
    for (int i = 0; i < NUM_SIDES; i++) {
        if (counts[i] > 0) {
            consecutiveCount++;
            if (consecutiveCount == 4) {
                return true;
            }
        } else {
            consecutiveCount = 0;
        }
    }
    return false;
}

int decidePlay(const int dice[]) {
    int counts[NUM_SIDES] = {0};
    countNumber(dice, counts);

    if (isYahtzee(dice)) {
        return YAHTZEE;
    } else if (isFullHouse(counts)) {
        return FULL_HOUSE;
    } else if (isFourOfAKind(counts)) {
        return FOUR_OF_A_KIND;
    } else if (isThreeOfAKind(counts)) {
        return THREE_OF_A_KIND;
    } else if (isLargeStraight(counts)) {
        return L_STRAIGHT;
    } else if (isSmallStraight(counts)) {
        return S_STRAIGHT;
    } else {
        return NO_PLAY;
    }
}
