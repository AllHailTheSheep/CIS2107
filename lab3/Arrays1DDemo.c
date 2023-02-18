#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void printArray(int*, size_t, char*);
void fillArray(int*, size_t, int, int);
int findWithRange(int*, size_t, int, int);
void reverseArray(int*, size_t);

int main() {
    int arr[100];
    // fillArray demo
    fillArray(arr, sizeof(arr)/sizeof(arr[0]), 0, 100);
    printArray(arr, sizeof(arr)/sizeof(arr[0]), "");

    // findWithRange demo
    // will fail because min is less than 0
    // findWithRange(arr, 100, -1, 40);
    // will fail because max is greater than the size of the array
    // findWithRange(arr, 100, 0, 100);
    // will fail because mindex == maxdex
    // findWithRange(arr, 100, 1, 1);
    // note that the mindex and maxdex params are interchangeable
    printf("max from 0-25: %d\n", findWithRange(arr, sizeof(arr)/sizeof(arr[0]), 0, 25));
    printf("max from 25-0: %d\n", findWithRange(arr, sizeof(arr)/sizeof(arr[0]), 25, 0));
    printf("max from 90-99: %d\n", findWithRange(arr, sizeof(arr)/sizeof(arr[0]), 90, 99));
    
    // reverseArray demo
    reverseArray(arr, sizeof(arr)/sizeof(arr[0]));
    printArray(arr, sizeof(arr)/sizeof(arr[0]), "Reversed array: ");
}

void printArray(int* arr, size_t size, char* prefix) {
    if (strlen(prefix) != 0) {
        printf("%s", prefix);
    }
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void fillArray(int* arr, size_t size, int rand_min, int rand_max) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % (rand_max - rand_min + 1) + rand_min;
    }
    return;
}

int findWithRange(int* arr, size_t size, int mindex, int maxdex) {
    if (mindex > maxdex) {
        int swp = mindex;
        mindex = maxdex;
        maxdex = swp;
    }
    if (mindex < 0 || maxdex > size || mindex == maxdex) {
        printf("%s\n", "Minimum must be greater than 0 and max must be less than the size of the array!");
        exit(EXIT_FAILURE);
    }
    int max = INT_MIN;
    for (int i = mindex; i <= maxdex; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void reverseArray(int* arr, size_t size) {
    // thanks to https://stackoverflow.com/questions/47745149/reverse-an-integer-array-in-c
    // for the idea to do it in-place
    int i = 0, j = size - 1;
    while (j > i) {
        int swp = arr[j];
        arr[j] = arr[i];
        arr[i] = swp;
        i++; j--;
    }
    return;
}
