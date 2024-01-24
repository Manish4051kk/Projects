// header files
#include <stdio.h>

// main program
int main()
{
    // initialize the program
        // declare variable
    char name[25];

        // show title
            // function: printf
    printf("My First C Program\n");
    printf("==================\n\n");

    // get user input 
        // prompt the user for the name
            // function: printf
    printf("Type your name: ");

        // read the name from the user input
            // function: scanf
    scanf("%s", name);

    // show message
        // print out a message
            // function: printf
    printf("Hello World, %s!\n", name);

    // end program
        // print out a message
            // function: printf
    printf("\nEnd program.\n");

        // return success
    return 0;
}