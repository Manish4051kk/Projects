#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, finalAmount, interest;
    int years, frequency;

    // Print title
    printf("Compound Interest Calculator:\n");
    printf("============================================\n\n");

    // Prompt user for input
    printf("Input the value of principal amount in USD: ");
    scanf("%lf", &principal);

    printf("Input the value of interest rate in %%: ");
    scanf("%lf", &rate);

    printf("Input the value of compounding frequency: ");
    scanf("%d", &frequency);

    printf("Input the value of time in years: ");
    scanf("%d", &years);

    // Convert percentage interest rate to decimal
    rate = rate / 100.0;

    // Calculate final amount using compound interest formula
    finalAmount = principal * pow(1 + rate / frequency, frequency * years);

    // Calculate interest charged
    interest = finalAmount - principal;

    // Print the result
    printf("The final amount is %.2lf USD", finalAmount);
    printf(" and the interest charged is %.2lf USD\n\n", interest);

    // End program
    printf("End of program\n");

    return 0;
}
