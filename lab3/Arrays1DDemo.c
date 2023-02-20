#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>

// function prototypes
void printArray(int*, size_t, char*);
void fillArray(int*, size_t, int, int);
int findWithRange(int*, size_t, int, int);
void reverseArray(int*, size_t);
void reverseSelectedRangeWithinArray(int*, size_t, int, int);
int findSequence(int*, size_t, int*, size_t);

const int SIZE = 25;
int main() {
    int arr[SIZE];
    // fillArray demo
    printf("%s\n", "fillArray demo:");
    fillArray(arr, SIZE, 0, SIZE);
    printArray(arr, SIZE, "filled array: ");

    // findWithRange demo
    printf("%s\n", "findWithRange demo:");
    // will fail because min is less than 0
    // findWithRange(arr, SIZE, -1, SIZE/2);
    // will fail because max is greater than the size of the array
    // findWithRange(arr, SIZE, 0, SIZE + 1);
    // will fail because mindex == maxdex
    // findWithRange(arr, SIZE, 1, 1);
    // note that the mindex and maxdex params are interchangeable
    printf("max from 0-%d: %d\n", SIZE/4, findWithRange(arr, SIZE, 0, SIZE/4));
    printf("max from %d-0: %d\n", SIZE/4, findWithRange(arr, SIZE, SIZE/4, 0));
    printf("max from %d-%d: %d\n\n", SIZE - (SIZE/10), SIZE - 1, findWithRange(arr, SIZE, (SIZE - (SIZE/10)), SIZE - 1));
    
    // reverseArray demo
    printf("%s\n", "reverseArray demo:");
    reverseArray(arr, SIZE);
    printArray(arr, SIZE, "reversed array: ");

    // reverseSelectedRangeWithinArray demo
    printf("%s\n", "reverseSelectedRangeWithinArray demo:");
    // will fail because min is less than 0
    // reverseSelectedRangeWithinArray(arr, SIZE, -1, SIZE/2);
    // will fail because max is greater than the size of the array
    // reverseSelectedRangeWithinArray(arr, SIZE, 0, SIZE + 1);
    // will fail because min == max
    // reverseSelectedRangeWithinArray(arr, SIZE, 1, 1);
    // again, note that mindex and maxdex params are interchangeable
    reverseSelectedRangeWithinArray(arr, SIZE, 0, SIZE/4);
    char* str = malloc(64 * sizeof(char));
    snprintf(str, 64, "reversed from 0-%d: ", SIZE/4);
    printArray(arr, SIZE, str);

    reverseSelectedRangeWithinArray(arr, SIZE, SIZE/4, 0);
    char* str1 = malloc(64 * sizeof(char));
    snprintf(str1, 64, "reversed from %d-0: ", SIZE/4);
    printArray(arr, SIZE, str1);

    reverseSelectedRangeWithinArray(arr, SIZE, SIZE/2 + SIZE/4, SIZE);
    char* str2 = malloc(64 * sizeof(char));
    snprintf(str2, 64, "reversed from %d-%d: ", SIZE/2 + SIZE/4, SIZE);
    printArray(arr, SIZE, str2);
    free(str); free(str1); free(str2);

    // findSequence demo
    // this is the array i first filled and designed this demo around
    int arr1[100] = {0, 43, 23, 10, 22, 20, 15, 13, 31, 2, 62, 72, 67, 88, 33, 86, 30, 9, 87, 75, 68, 15, 60, 47, 76, 45, 49, 57, 89, 53, 56, 70, 28, 65, 26, 30, 33, 19, 30, 41, 46, 43, 21, 42, 80, 50, 10, 98, 84, 33, 24, 27, 72, 66, 61, 90, 79, 36, 68, 15, 46, 73, 14, 21, 100, 93, 40, 7, 29, 80, 30, 67, 63, 2, 64, 84, 29, 64, 74, 66, 53, 49, 41, 2, 60, 38, 23, 21, 47, 58, 3, 29, 89, 81, 70, 16, 7, 14, 59, 62};
    printArray(arr1, 100, "array to be searched: ");
    printf("%s\n", "findSequence demo:");
    int s[3] = {43, 23, 10};
    printf("%s%d\n", "sequence 43, 23, 10 found at index: ", findSequence(arr1, 100, s, sizeof(s)/sizeof(s[0])));
    int s1[2] = {7, 14};
    printf("%s%d\n", "sequence 7, 14 found at index: ", findSequence(arr1, 100, s1, sizeof(s1)/sizeof(s1[0])));
    int s2[5] = {40, 7, 29, 80, 30};
    printf("%s%d\n", "sequence 40, 7, 29, 80, 30 found at index: ", findSequence(arr1, 100, s2, sizeof(s2)/sizeof(s2[0])));
    return EXIT_SUCCESS;
}

/**
 * Prints an array. If prefix is "" then it will not print anything.
 * @param arr the array to print.
 * @param size the size of the array passed in.
 * @param prefix the prefix to print before the array is printed.
 * TODO: add a suffix param?
*/
void printArray(int* arr, size_t size, char* prefix) {
    if (strlen(prefix) != 0) {
        printf("%s", prefix);
    }
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    return;
}

/**
 * Fills an array randomly with numbers between rand_min and rand_max (inclusive).
 * Make sure to uncomment srand(time(NULL)) for less reproducible results.
 * @param arr the pre-allocated array to fill.
 * @param size the size of the array to be filled.
 * @param rand_min the minimum value to be used.
 * @param rand_max the maximum value to be used.
*/
void fillArray(int* arr, size_t size, int rand_min, int rand_max) {
    // srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % (rand_max - rand_min + 1) + rand_min;
    }
    return;
}

/**
 * Finds the maximum value between two indexes inclusively.
 * @param arr the array to search.
 * @param size the size of the array to search.
 * @param mindex the start index.
 * @param maxdex the end index.
 * @return the maximum value between the indexes.
*/
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

/**
 * Reverses an array.
 * @param arr the array to reverse.
 * @param size the size of the array to reverse.
*/
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

/**
 * Reverses from the lower bound to the upper bound inclusively.
 * @param arr array to reverse part of.
 * @param size the size of the array to reverse part of.
 * @param mindex the index to start reversal at.
 * @param maxded the index to end reversal at.
*/
void reverseSelectedRangeWithinArray(int* arr, size_t size, int mindex, int maxdex) {
    if (mindex > maxdex) {
        int swp = mindex;
        mindex = maxdex;
        maxdex = swp;
    }
    if (mindex < 0 || maxdex > size || mindex == maxdex) {
        printf("%s\n", "Minimum must be greater than 0 and max must be less than the size of the array!");
        exit(EXIT_FAILURE);
    }
    int i = mindex, j = maxdex - 1;
    while (j > i) {
        int swp = arr[j];
        arr[j] = arr[i];
        arr[i] = swp;
        i++; j--;
    }
    return;
}

/** 
 * Finds the index where the numbers in toFind occur in order in the array.
 * @param arr the array to search.
 * @param arr_s the size of the array to search.
 * @param toFind the sequence to search for.
 * @param toFind_s the size of the sequence to search for.
 * @return the index the sequence was found begins at.
*/
int findSequence(int* arr, size_t arr_s, int* toFind, size_t toFind_s) {
    if (toFind_s == 0 || toFind_s > arr_s) {
        printf("%s\n", "There must be something to find and it must be less then the size of the array.");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < arr_s; i++) {
        int count = 0;
        for (int j = 0; j < toFind_s; j++) {
            if (arr[i+j] == toFind[j]) {
                count++;
            } else {
                break;
            }
        }
        if (count == toFind_s) {
            return i;
        }
    }
    return -1;
}
