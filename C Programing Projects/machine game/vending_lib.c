#include "vending_lib.h"

const char* prodDesc[NUM_PRODUCTS] = {
    "Hershey's Milk Chocolate Bar 1.55oz",
    "Chips",
    "Chewing Gum",
    "Pepsi Soda 20oz Bottle"
};

/**
 * Name: stockMachine
 * Process: Initializes the vending machine with predefined products.
 * Function input/parameters:
 *     products - Array of Product structures representing vending machine products
 * Function output/parameters: None
 * Function output/returned: None
 * Dependencies: None
 **/

void stockMachine(Product products[]) {
    // In a real system, this function would read from a file
    // For simplicity, let's initialize some values here
    products[CHOCOLATE_BAR].type = CHOCOLATE_BAR;
    products[CHOCOLATE_BAR].price = 2.30;
    products[CHOCOLATE_BAR].quantity = 15;

    products[CHIPS].type = CHIPS;
    products[CHIPS].price = 1.50;
    products[CHIPS].quantity = 10;

    products[CHEWING_GUM].type = CHEWING_GUM;
    products[CHEWING_GUM].price = 1.00;
    products[CHEWING_GUM].quantity = 20;

    products[PEPSI].type = PEPSI;
    products[PEPSI].price = 1.99;
    products[PEPSI].quantity = 7;
}

/**
 * Name: displayProducts
 * Process: Displays the list of available products in a tabular format.
 * Function input/parameters:
 *     products - Array of Product structures representing vending machine products
 * Function output/parameters: None
 * Function output/returned: None
 * Dependencies: None
 **/
void displayProducts(Product products[]) {
    printf("Code | Product Description                 | Available Quantity | Unit Price\n");
    printf("-----|-------------------------------------|--------------------|------------\n");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        printf("%4d | %-35s | %18d | %8.2f\n",
               i, prodDesc[i], products[i].quantity, products[i].price);
    }
}

/**
 * Name: getProduct
 * Process: Prompts the user to select a product by entering its code.
 * Function input/parameters:
 *     products - Array of Product structures representing vending machine products
 * Function output/parameters: ProductType - The selected product's type
 * Function output/returned: None
 * Dependencies: None
 **/
ProductType getProduct(Product products[]) {
    int code;
    do {
        printf("\nEnter the code of the product you want to purchase (or -1 to cancel): ", NUM_PRODUCTS - 1);
        scanf("%d", &code);
        if (code == ABORT) {
            return ABORT;
        } else if (code < 0 || code >= NUM_PRODUCTS) {
            printf("Invalid product code. Please try again.\n");
        }
    } while (code < 0 || code >= NUM_PRODUCTS);
    return (ProductType)code;
}

/**
 * Name: getQuantity
 * Process: Prompts the user to enter the quantity of a selected product.
 * Function input/parameters:
 *     products - Array of Product structures representing vending machine products
 *     productType - The type of the selected product
 * Function output/parameters: int - The entered quantity
 * Function output/returned: None
 * Dependencies: None
 **/
int getQuantity(Product products[], ProductType productType) {
    int quantity;
    do {
        printf("Enter the quantity of %s you want to purchase: ", prodDesc[productType]);
        scanf("%d", &quantity);
        if (quantity <= 0) {
            printf("Invalid quantity. Please enter a number greater than 0.\n");
        } else if (quantity > products[productType].quantity) {
            printf("Insufficient quantity. Please enter a smaller quantity.\n\n");
        }
    } while (quantity <= 0 || quantity > products[productType].quantity);
    return quantity;
}

/**
 * Name: selectItem
 * Process: Creates a CartItem based on the selected product and quantity.
 * Function input/parameters:
 *     products - Array of Product structures representing vending machine products
 *     productType - The type of the selected product
 *     quantity - The quantity of the selected product
 * Function output/parameters: CartItem - The created cart item
 * Function output/returned: None
 * Dependencies: None
 **/
CartItem selectItem(Product products[], ProductType productType, int quantity) {
    CartItem item;
    item.product = products[productType];
    item.quantity = quantity;
    products[productType].quantity -= quantity;
    return item;
}

/**
 * Name: addToCart
 * Process: Adds a CartItem to the shopping cart and updates the total cost.
 * Function input/parameters:
 *     cart - Pointer to the shopping cart
 *     item - The CartItem to add
 * Function output/parameters: bool - True if added successfully, False otherwise
 * Function output/returned: None
 * Dependencies: None
 **/
bool addToCart(ShoppingCart *cart, CartItem item) {
    if (cart->num_items >= MAX_NUM_PRODUCTS) {
        printf("Shopping cart is full! Cannot add more items.\n");
        return false;
    }
    cart->items[cart->num_items] = item;
    cart->num_items++;
    cart->total_cost += item.product.price * item.quantity;
    return true;
}

/**
 * Name: cancelPurchase
 * Process: Cancels the purchase, restores product quantities, and resets the shopping cart.
 * Function input/parameters:
 *     cart - Pointer to the shopping cart
 *     products - Array of Product structures representing vending machine products
 * Function output/parameters: None
 * Function output/returned: None
 * Dependencies: None
 **/
void cancelPurchase(ShoppingCart *cart, Product products[]) {
    for (int i = 0; i < cart->num_items; i++) {
        products[cart->items[i].product.type].quantity += cart->items[i].quantity;
    }
    cart->num_items = 0;
    cart->total_cost = 0;
}

/**
 * Name: generateBill
 * Process: Generates and displays a bill for the items in the shopping cart.
 * Function input/parameters:
 *     cart - Pointer to the shopping cart
 * Function output/parameters: None
 * Function output/returned: None
 * Dependencies: None
 **/
void generateBill(ShoppingCart *cart) {
    printf("\nProduct                                 | Unit Price | Product total\n");
    printf("----------------------------------------|------------|--------------\n");
    for (int i = 0; i < cart->num_items; i++) {
        printf("%4d x %-32s | %8.2f x %2d | %8.2f\n",
               cart->items[i].quantity, prodDesc[cart->items[i].product.type],
               cart->items[i].product.price, cart->items[i].quantity,
               cart->items[i].product.price * cart->items[i].quantity);
    }
    printf("Order Total: %.2f\n\n", cart->total_cost);
}

/**
 * Name: pay
 * Process: Handles the payment process, including different payment methods, service fees, and change.
 * Function input/parameters:
 *     cart - Pointer to the shopping cart
 * Function output/parameters: bool - True if payment successful, False otherwise
 * Function output/returned: None
 * Dependencies: None
 **/
bool pay(ShoppingCart *cart) {
    int paymentMethod;
    float paidAmount, serviceFee = 0.0;
    
    printf("Select payment method:\n");
    printf("0. Cash\n");
    printf("1. Credit Card\n");
    printf("2. Contactless\n");
    scanf("%d", &paymentMethod);
    
    switch (paymentMethod) {
		case CASH: {
			do 
			{
				printf("Enter the amount paid: ");
				scanf("%f", &paidAmount);

				if (paidAmount < cart->total_cost) 
				{
					printf("Insufficient amount. Please enter a higher amount.\n");
				}
			} while (paidAmount < cart->total_cost);

			printf("-------------\n");
			printf("Paid by: Cash\n");
			printf("Service Fee: %.2f\n", serviceFee);
			printf("Paid amount: %.2f\n", paidAmount);
			printf("Change: %.2f\n", paidAmount - cart->total_cost);
			break;
		}

        case CREDIT: {
            int creditCard;
            printf("\nSelect Credit Card:\n");
            printf("0. MasterCard\n");
            printf("1. Visa\n");
            printf("2. Discover\n");
            printf("3. American Express\n");
            scanf("%d", &creditCard);
            
            switch (creditCard) {
                case MASTERCARD:
                    printf("\nPaid by: Credit Card (MasterCard)\n");
                    break;
                case VISA:
                    printf("\nPaid by: Credit Card (Visa)\n");
                    break;
                case DISCOVER:
                    printf("\nPaid by: Credit Card (Discover)\n");
                    break;
                case AMERICAN_EXPRESS:
                    printf("\nPaid by: Credit Card (American Express)\n");
                    break;
                default:
                    printf("\nInvalid credit card selection. Payment failed.\n");
                    return false;
            }
            
            serviceFee = cart->total_cost * 0.0002;  // 0.02%
            printf("Service Fee: %.2f\n", serviceFee);
            printf("Paid amount: %.2f\n", cart->total_cost + serviceFee);
            printf("Change: 0.00\n");
            break;
        }
        case CONTACTLESS: {
            int contactlessMethod;
            printf("Select Contactless Payment:\n");
            printf("0. Google Wallet\n");
            printf("1. Apple Pay\n");
            scanf("%d", &contactlessMethod);
            
            switch (contactlessMethod) {
                case GOOGLE_WALLET:
                    printf("Paid by: Contactless Payment (Google Wallet)\n");
                    break;
                case APPLE_PAY:
                    printf("Paid by: Contactless Payment (Apple Pay)\n");
                    break;
                default:
                    printf("Invalid contactless payment selection. Payment failed.\n");
                    return false;
            }
            
            serviceFee = cart->total_cost * 0.0001;  // 0.01%
            printf("Service Fee: %.2f\n", serviceFee);
            printf("Paid amount: %.2f\n", cart->total_cost + serviceFee);
            printf("Change: 0.00\n");
            break;
        }
        default:
            printf("Invalid payment method. Payment failed.\n");
            return false;
    }
    
    return true;
}