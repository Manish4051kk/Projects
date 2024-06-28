#include <stdio.h>

int main() {
    // Iterate through numbers from 1 to 100
    for (int i = 1; i <= 100; i++) {
        // Check if the number is even
        if (i % 2 == 0) {
            // Print the even number
            printf("%d ", i);
        }
    }
    return 0;
}
