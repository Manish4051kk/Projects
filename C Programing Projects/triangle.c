// header file
#include <stdio.h>
// main program
int main()
{
    // initialize program
        // show title
            // function: printf
    printf("Triangle Validation\n");
    printf("===================\n\n");
        // declare variables
    int side1, side2, side3;
    // get user input
        // prompt and read side 1
            // functions: printf, scanf
    printf("Type the length of side 1: ");
    scanf("%d", &side1);
        // prompt and read side 2
            // functions: printf, scanf
    printf("Type the length of side 2: ");
    scanf("%d", &side2);
        // prompt and read side 3
            // functions: printf, scanf
    printf("Type the length of side 3: ");
    scanf("%d", &side3);

    // check if the lengths form a triangle
        // if the sum of any two sides is greater than the third side

    if (side1 + side2 >side3 && side1 + side3 >side2 && side3 + side2 >side1)
    {
        // inform that the sides form a triangle
            // function: printf
        printf("These lengths can form a triangle.\n");
    }
    // otherwise
    else
    {
        // inform that the sides do NOT form a triangle
            // function: printf
        printf("These lengths cannot form a triangle.\n");
    }
    // end program
        // print a message
            // function: printf
    printf("End of program\n");
        // return success
    return 0;
}
