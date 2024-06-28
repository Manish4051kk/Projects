// inclusion guards
#ifndef TOWEROFHANOI_LIB_H
#define TOWEROFHANOI_LIB_H

// header files
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// global constants
    // value representing empty index (no disks)
#define EMPTY_VALUE 0
    // total number of disks
#define TOTAL_DISKS 3
    // maximum tower size
#define TOWER_SIZE 3 

// function prototypes
/**
 * Name: initializeTower
 * Process: initialize a tower with disks in ascending order
 * Function input/parameters:
            tower - an array representing the tower
            nDisks - pointer to the number of disks in the array
 * Function output/parameters: 
 *          both parameters will be updated at the end of the function
 * Function output/returned: none
 * Dependencies: none
 **/
void initializeTower(int* tower, int* nDisks);

/**
 * Name: addDisk
 * Process: add a given disk to the given tower and update the number of
 *          disks in the tower
 * Function input/parameters: 
 *          tower - an array representing the tower
 *          nDisks - pointer to the number of disks in the array
 *          disk - disk to be added to be tower  
 * Function output/parameters:
 *          tower - updated array
 *          nDisks - updated number of disks
 * Function output/returned: none
 * Dependencies: none
 **/
void addDisk(int* tower, int* nDisks, int disk);

/**
 * Name: getDisk
 * Process: remove the top disk of the tower and update the number of disks
 * Function input/parameters: 
            tower - an array representing the tower
            nDisks - pointer to the number of disks in the array  
 * Function output/parameters:
 *          both parameters will be updated at the end of the function
 * Function output/returned: number representing the removed disk
 * Dependencies: none
 **/
int getDisk(int* tower, int* nDisks);

/**
 * Name: moveDisk
 * Process: moves a disk from the source tower to the destination tower
 * Function input/parameters: 
 *          sourceTower - an array representing the source tower
 *          destinationTower - an array representing the destination tower
 *          nDisksSource - pointer to the number of disks in the source tower
 *          nDisksDest - pointer to the number of disks in the dest tower
 * Function output/parameters: 
 *          all the parameters will be updated at the end of the function
 * Function output/returned: none
 * Dependencies: towerOfHanoi_lib.h - getDisk, addDisk
 **/
void moveDisk(int* sourceTower, int* destinationTower,
              int* nDisksSource, int* nDisksDest);

/**
 * Name: getTotalMoves
 * Process: find the total number of moves necessary to solve the puzzle
 * Function input/parameters: none       
 * Function output/parameters: none
 * Function output/returned: total number of moves
 * Dependencies: none
 **/
int getTotalMoves();

/**
 * Name: towerOfHanoi
 * Process: Implement the towerofHanoi puzzle
 * Function input/parameters:
            sourceTower - an array representing the source tower
            auxTower - an array representing the auxiliary tower
            destinationTower - an array representing the destination tower
            nDisksSource - pointer to the number of disks in the source tower
            nDisksAux - pointer to the number of disks in the auxiliary tower
            nDisksDest - pointer to the number of disks in the dest tower
 * Function output/parameters:
            all the parameters will be updated at the end of the function
 * Function output/returned: none
 * Dependencies: towerOfHanoi_lib.h - initializeTower, 
 *          getTotalMoves, printTower, moveDisk
 **/
void towerOfHanoi(int* sourceTower, int* auxTower, int* destinationTower,
                    int* nDisksSource,int* nDisksAux,int* nDisksDest);

/**
 * Name: printTower
 * Process: Print the current status of all towers
 * Function input/parameters:
 *          sourceTower - an array representing the disks in source tower
 *          auxTower - an array representing the disks in auxiliary tower
 *          destinationTower - an array representing the disks in 
 *                             destination tower
 *          nDisksSource - the number of disks in the source tower
 *          nDisksAux - the number of disks in the auxiliary tower
 *          nDisksDest - the number of disks in the dest tower
 * Function output/parameters: none
 * Function output/returned: none
 * Dependencies: stdio.h - printf
 **/
void printTower(const int* sourceTower, const int* auxTower,
    const int* destinationTower, const int nDisksSource, const int nDisksAux,
    const int nDisksDest);

#endif