#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// function prototypes
void fill2DArray(int rows, int cols, int[][cols], bool rand);
void displayOuputs(int rows, int cols, int[][cols]);
void getUserInput(int*, int*, bool*);
int max(int rows, int cols, int[][cols]);
int rowSum(int, int rows, int cols, int[][cols]);
int colSum(int, int rows, int cols, int[][cols]);
bool isSquare(int, int);

int main() {
    // default for variables i like using during testing
    int rows = 3;
    int cols = 4;
    bool randomize = true;
    // TODO: make sure this line is uncommented before submission!
    getUserInput(&rows, &cols, &randomize);
    int arr[rows][cols];
    // fill and print array
    fill2DArray(rows, cols, arr, randomize);

    // print max of array
    printf("Max of array: %d\n\n", max(rows, cols, arr));

    // print sums of rows
    for (int i = 0; i < rows; i++) {
        printf("Sum of row %d: %d\n", i, rowSum(i, rows, cols, arr));
    }
    printf("%s", "\n");

    // print sums of columns
    for (int i = 0; i < cols; i++) {
        printf("Sum of column %d: %d\n", i, colSum(i, rows, cols, arr));
    }
    printf("%s", "\n");

    // print if array is square or not
    printf("Array is sqaure: %s\n\n", isSquare(rows, cols) ? "true" : "false");

    // print array
    printf("%s\n", "Array:");
    displayOuputs(rows, cols, arr);
    return EXIT_SUCCESS;
}

/**
 * Fills a 2d array, either randomly or with user inputs.
 * Uncomment srand(time(NULL)); for less reproducible results.
 * @p rows the number of rows in the array.
 * @p cols the number of columns in the array.
 * @p arr the array to be filled.
 * @p randomize whether or not to fill the array randomly (true) or with user inputs (false).
*/
void fill2DArray(int rows, int cols, int arr[rows][cols], bool randomize) {
    if (randomize) {
        // uncomment this for random initialization
        // srand(time(NULL));
        int min = 0, max = 100;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = rand() % (max - min + 1) + min;
            }
        }
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("Enter item index [%d][%d]: ", i, j);
                int s;
                scanf("%d", &s);
                arr[i][j] = s;
            }
        }
    }
}

/** 
 * Prints a 2d array.
 * @p rows the number of rows in the array.
 * @p cols the number of columns in the array.
 * @p arr the array to print
*/
void displayOuputs(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == 0) {
                printf("[%d, ", arr[i][j]);
            } else if (j == cols - 1) {
                printf("%d]\n", arr[i][j]);
            } else
            printf("%d, ", arr[i][j]);
        }
    }
}

/**
 * Takes user input and reads them into rows, cols, and randomize pointers.
 * @p rows an int pointer to the number of rows.
 * @p cols an int pointer to the number of columns.
 * @p randomize a boolean pointer to the random/user input flag.
*/
void getUserInput(int* rows, int* cols, bool* randomize) {
    printf("%s", "How many rows? ");
    int i;
    scanf("%d", &i);
    *rows = i;

    printf("%s", "How many columns? ");
    int j;
    scanf("%d", &j);
    *cols = j;

    printf("%s", "Should the array be filled randomly? (y/n) ");
    char c;
    scanf(" %c", &c);
    if (c == 'y' || c == 'Y') {
        *randomize = true;
    } else {
        *randomize = false;
    }
}

/**
 * Returns the max int that occurs in a 2d array.
 * @p rows the number of rows in the array.
 * @p cols the number of columns in the array.
 * @p arr the array to search.
 * @return the max int that occurs in the array.
*/
int max(int rows, int cols, int arr[rows][cols]) {
    int max = INT_MIN;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

/**
 * Returns the sum of the elements in the specified row.
 * @p row the row to sum.
 * @p rows the number of rows in the array.
 * @p cols the number of columns in the array.
 * @p arr the array t sum a single row of.
 * @return the sum of the elements in the specified row.
*/
int rowSum(int row, int rows, int cols, int arr[rows][cols]) {
    int sum = 0;
    for (int i = 0; i < cols; i++) {
        sum += arr[row][i];
    }
    return sum;
}

/**
 * Returns the sum of the elements in the specified column.
 * @p col the column to sum.
 * @p rows the number of rows in the array.
 * @p cols the number of columns in the array.
 * @p arr the array t sum a single column of.
 * @return the sum of the elements in the specified column.
*/
int colSum(int col, int rows, int cols, int arr[rows][cols]) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += arr[i][col];
    }
    return sum;
}

/**
 * Returns true if the number or rows is equal to the number of columns.
 * @p rows the number of rows in the array (if unknown, use sizeof(arr)/sizeof(arr[0])).
 * @p cols the number of columns in the array (if unknown, use sizeof(arr[0])/sizeof(arr[0][0])).
 * @return true if the array is square, false otherwise.
*/
bool isSquare(int rows, int cols) {
    return rows == cols ? true : false;
}