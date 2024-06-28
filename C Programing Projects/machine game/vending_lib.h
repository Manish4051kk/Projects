#ifndef VENDING_LIB_H
#define VENDING_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define ABORT -1
#define MAX_NUM_PRODUCTS 100

// Enums
typedef enum {
    CHOCOLATE_BAR,
    CHIPS,
    CHEWING_GUM,
    PEPSI,
    NUM_PRODUCTS
} ProductType;

typedef enum {
    CANCEL = -1,
    CHECKOUT,
    CONTINUE
} Menu;

typedef enum {
    CASH,
    CREDIT,
    CONTACTLESS
} Payment;

typedef enum {
    MASTERCARD,
    VISA,
    DISCOVER,
    AMERICAN_EXPRESS
} CreditCard;

typedef enum {
    GOOGLE_WALLET,
    APPLE_PAY
} Contactless;

// Structs
typedef struct {
    ProductType type;
    float price;
    int quantity;
} Product;

typedef struct {
    Product product;
    int quantity;
} CartItem;

typedef struct {
    CartItem items[MAX_NUM_PRODUCTS];
    int num_items;
    float total_cost;
} ShoppingCart;

// Function prototypes
extern const char* prodDesc[NUM_PRODUCTS];

void stockMachine(Product products[]);
void displayProducts(Product products[]);
ProductType getProduct(Product products[]);
int getQuantity(Product products[], ProductType productType);
CartItem selectItem(Product products[], ProductType productType, int quantity);
bool addToCart(ShoppingCart *cart, CartItem item);
void cancelPurchase(ShoppingCart *cart, Product products[]);
void generateBill(ShoppingCart *cart);
bool pay(ShoppingCart *cart);

#endif
