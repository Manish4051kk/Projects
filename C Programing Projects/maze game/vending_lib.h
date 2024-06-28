#ifndef VENDING_LIB_H
#define VENDING_LIB_H

#include <stdio.h>
#include <stdbool.h>

#define ABORT -1
#define MAX_NUM_PRODUCTS 100

extern const char* prodDesc[MAX_NUM_PRODUCTS];

enum ProductType {
    CHOCOLATE_BAR,
    CHIPS,
    CHEWING_GUM,
    PEPSI,
    NUM_PRODUCTS
};

enum Menu {
    CANCEL = -1,
    CHECKOUT,
    CONTINUE
};

enum Payment {
    CASH,
    CREDIT,
    CONTACTLESS
};

enum CreditCard {
    MASTERCARD,
    VISA,
    DISCOVER,
    AMERICAN_EXPRESS
};

enum Contactless {
    GOOGLE_WALLET,
    APPLE_PAY
};

struct Product {
    enum ProductType type;
    float price;
    int quantity;
};

struct CartItem {
    struct Product product;
    int quantity;
};

struct ShoppingCart {
    struct CartItem items[MAX_NUM_PRODUCTS];
    int itemCount;
    float totalCost;
};

void stockMachine(struct Product products[]);
void displayProducts(const struct Product products[]);
int getProduct(const struct Product products[]);
int getQuantity(int productCode, const struct Product products[]);
struct CartItem selectItem(int productCode, int quantity, struct Product products[]);
bool addToCart(struct CartItem item, struct ShoppingCart *cart);
void cancelPurchase(struct ShoppingCart *cart, struct Product products[]);
void generateBill(const struct ShoppingCart *cart);
bool pay(float totalCost, struct ShoppingCart *cart);

#endif /* VENDING_LIB_H */
