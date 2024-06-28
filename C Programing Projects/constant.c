#include <stdio.h>

// Global constant
const int PI = 3.14;

// Global macro
#define MACRO 40

int main() {
    // Local variable with block scope inside main
    int local_var_main = 30;

    // Local constant with block scope inside main
    const int local_const  = 40;

    // Printing the values of the variables
    printf("Global constant: %d\n", PI);
    printf("Global macro: %d\n", MACRO);
    printf("Local variable (main): %d\n", local_var_main);
    printf("Local constant (main): %d\n", local_const);

    // Local variable with block scope inside an if statement
    if (1) {
        const int block_var = 50;
        int local_var_if = 60;

        printf("Local constant (if): %d\n", block_var);
        printf("Local variable (if): %d\n", local_var_if);
    }

    return 0;
}