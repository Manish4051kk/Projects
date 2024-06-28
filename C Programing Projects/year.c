// header files
#include <stdio.h>
// main program
int main()
{
    // initialize program
        // show title
            // function: printf
    printf("Convert days to years, weeks, and days\n");
    printf("======================================\n\n");
        // declare variables
    int days, years, weeks;
    // get user input
        // prompt for days
            // function: printf
    printf("Type the total number of days: ");
        // read days
            // function: scanf
    scanf("%d", &days);
    
    // converts days to years, weeks and days
        // calculate the number of years

    years = days/365;
        // calculate the number of weeks with the remaining days

    weeks = (days - years*365)/7;
        // calculate the number of remaining days

    days = days - (years*365+weeks*7);

    // Print the result
        // function: printf
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d \n", days);

    // end program
        // print a message
            // function: printf
    printf("End of program");
        // return success
    return 0;
}
