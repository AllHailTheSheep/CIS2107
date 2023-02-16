#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int*, size_t);
void fillArray(int*, size_t, int, int);

int main() {
    int arr0[6];
    fillArray(arr0, 6, 0, 10);
    printArray(arr0, 6);
}

void printArray(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void fillArray(int* arr, size_t size, int rand_min, int rand_max) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % (rand_max - rand_min + 1) + rand_min;
    }
    return;
}