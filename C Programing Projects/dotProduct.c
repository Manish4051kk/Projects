#include "dotProduct.h"

int dotProduct(int arr1[], int arr2[], int size) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result += arr1[i] * arr2[i];
    }
    return result;
}
