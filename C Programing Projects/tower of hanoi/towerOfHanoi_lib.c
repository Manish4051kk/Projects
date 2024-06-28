// include the towerOfHanoi_lib.h header file
#include "towerOfHanoi_lib.h"

// Function to initialize the tower with disks in ascending order
void initializeTower(int* tower, int* nDisks) {
    for (int i = 0; i < TOTAL_DISKS; ++i) {
        tower[i] = i + 1;
    }
    *nDisks = TOTAL_DISKS;
}

// Function to add a disk to the tower
void addDisk(int* tower, int* nDisks, int disk) {
    for (int i = *nDisks; i > 0; --i) {
        tower[i] = tower[i - 1];
    }
    tower[0] = disk;
    (*nDisks)++;
}

// Function to get the top disk from the tower
int getDisk(int* tower, int* nDisks) {
    int topDisk = tower[0];
    for (int i = 1; i < *nDisks; ++i) {
        tower[i - 1] = tower[i];
    }
    (*nDisks)--;
    return topDisk;
}

// Function to move a disk from source tower to destination tower
void moveDisk(int* sourceTower, int* destinationTower,
              int* nDisksSource, int* nDisksDest) {
    // Get the top disk from the source tower
    int disk = getDisk(sourceTower, nDisksSource);
    
    // Check if destination tower is empty or if the disk being moved is smaller than the top disk in the destination tower
    if (*nDisksDest == 0 || disk < destinationTower[0]) {
        // If the condition is met, move the disk to the destination tower
        addDisk(destinationTower, nDisksDest, disk);
    } else {
        // Otherwise, move the disk back to the source tower and move the top disk from the destination tower to the source tower
        addDisk(sourceTower, nDisksSource, disk);
        disk = getDisk(destinationTower, nDisksDest);
        addDisk(sourceTower, nDisksSource, disk);
    }
}




// Function to calculate the total number of moves
int getTotalMoves() {
    return (int)pow(2, TOTAL_DISKS) - 1;
}

// Function to implement the Tower of Hanoi puzzle
void towerOfHanoi(int* sourceTower, int* auxTower, int* destinationTower,
                    int* nDisksSource, int* nDisksAux, int* nDisksDest) {
    int moves = getTotalMoves();
    for (int i = 1; i <= moves; ++i) {
        if (i % TOTAL_DISKS == 0) {
            moveDisk(auxTower, destinationTower, nDisksAux, nDisksDest);
        } else if (i % TOTAL_DISKS == 1) {
            moveDisk(sourceTower, destinationTower, nDisksSource, nDisksDest);
        } else {
            moveDisk(sourceTower, auxTower, nDisksSource, nDisksAux);
        }
        printTower(sourceTower, auxTower, destinationTower, *nDisksSource, *nDisksAux, *nDisksDest);
    }
}

// Function to print the current status of all towers
void printTower(const int* sourceTower, const int* auxTower,
                const int* destinationTower, const int nDisksSource,
                const int nDisksAux, const int nDisksDest) {
    printf("src   aux   dst\n");
    printf("===============\n");

    // Print each tower's disks
    for (int i = 0; i < TOTAL_DISKS; ++i) {
        // Print disk from source tower
        if (i < nDisksSource)
            printf(" %d |", sourceTower[i]);
        else
            printf("   |");

        // Print disk from auxiliary tower
        if (i < nDisksAux)
            printf(" %d |", auxTower[i]);
        else
            printf("   |");

        // Print disk from destination tower
        if (i < nDisksDest)
            printf(" %d ", destinationTower[i]);
        else
            printf("   ");

        printf("\n");
    }
    printf("\n");
   
}
