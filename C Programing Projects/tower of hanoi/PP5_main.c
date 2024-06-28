#include <stdio.h>
#include "towerOfHanoi_lib.h"

int main() {
    // Initialize towers
    int sourceTower[TOTAL_DISKS] = {0};
    int auxTower[TOTAL_DISKS] = {0};
    int destinationTower[TOTAL_DISKS] = {0};
    int nDisksSource = 0, nDisksAux = 0, nDisksDest = 0;

    // Initialize source tower
    initializeTower(sourceTower, &nDisksSource);

    // Print initial state
    printf("\n  Welcome to Tower of Hanoi!\n");
    printf(" ===============================\n\n");
    printTower(sourceTower, auxTower, destinationTower, nDisksSource, nDisksAux, nDisksDest);

    // Run Tower of Hanoi simulation
    towerOfHanoi(sourceTower, auxTower, destinationTower, &nDisksSource, &nDisksAux, &nDisksDest);

	printf("\n\nSimulation ended.");
    return 0;
}
