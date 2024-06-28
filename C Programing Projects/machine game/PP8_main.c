#include <stdio.h>
#include "vending_lib.h"

int main() {
    Product products[NUM_PRODUCTS];
    ShoppingCart cart = { .num_items = 0, .total_cost = 0 };

    // Part I - Setup
    stockMachine(products);

    // Print title
    printf("Welcome to the Vending Machine!\n");

    // Part II - The vending machine
    while (true) {
        // Display available products
        displayProducts(products);

        // Get product selection
        ProductType selectedProduct = getProduct(products);

        // Check if user wants to abort
        if (selectedProduct == ABORT) {
            printf("Purchased Cancelled. Goodbye!\n");
            break;
        }

        // Get quantity
        int quantity = getQuantity(products, selectedProduct);

        // Select item
        CartItem item = selectItem(products, selectedProduct, quantity);

        // Add item to cart
        if (!addToCart(&cart, item)) {
            printf("Failed to add item to cart. Cart is full.\n");
            break;
        }

        // Check if cart is full
        if (cart.num_items >= MAX_NUM_PRODUCTS) {
            printf("Shopping cart is full. Proceeding to checkout.\n");
            break;
        }

        // Ask user to continue shopping or checkout
        int choice;
        do {
            printf("\n1. Continue shopping\n");
            printf("2. Cancel purchase\n");
            printf("3. Proceed to checkout\n");
            scanf("%d", &choice);

            if (choice < 1 || choice > 3) {
                printf("Invalid choice. Please try again.\n");
            }
        } while (choice < 1 || choice > 3);

        switch (choice) {
            case 1:
                // Continue shopping
                break;
            case 2:
                // Cancel purchase
                cancelPurchase(&cart, products);
                printf("Purchase canceled. Goodbye!\n");
                return 0;
            case 3:
                // Checkout
                generateBill(&cart);
                if (pay(&cart)) {
                    printf("\nThank you for your purchase!\n");
                    return 0;
                } else {
                    cancelPurchase(&cart, products);
                    printf("Payment failed. Purchase canceled. Goodbye!\n");
                    return 0;
                }
        }
    }

    return 0;
}
