// header files
#include <stdio.h>

// main program
int main()
{
    // initialize the program
        // declare variable
    int a;
    int b;
    char c;
    

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
    scanf("%d", a);
    
    printf("Type your name: ");

        // read the name from the user input
            // function: scanf
    scanf("%d", b);
    
    printf("Type your name: ");

        // read the name from the user input
            // function: scanf
    scanf("%s", c);

    // show message
        // print out a message
            // function: printf
    printf("%a %c %b!\n", a,b,c);

    // end program
        // print out a message
            // function: printf
    printf("\nEnd program.\n");

        // return success
    return 0;
}
