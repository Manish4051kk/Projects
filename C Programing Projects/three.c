// header files
#include <stdio.h>

// main program
int main()
{
    // initialize the program
        // declare variable
    int a;
    int b;

        // show title
            // function: printf
    printf("My First C Program\n");
    printf("==================\n\n");

    // get user input
        // prompt the user for the name
            // function: printf
    printf("number 1 ");

        // read the name from the user input
            // function: scanf
    scanf("%d", a);

    printf("number 2 ");

        // read the name from the user input
            // function: scanf
    scanf("%d", b);


    // show message
        // print out a message
            // function: printf
    printf("%a",a);
    printf("%b",b);

    // end program
        // print out a message
            // function: printf
    printf("\nEnd program.\n");

        // return success
    return 0;
}
