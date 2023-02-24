#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void fill2DArray(int row, int col, int[][col], bool rand);
void print2DArray(int row, int col, int[][col]);
void getUserInput(int*, int*, bool*);
int max(int row, int col, int[][col]);

int main() {
    // default for variables i like using during testing
    int ROW = 3;
    int COL = 8;
    bool randomize = true;
    // TODO: uncomment this before submission
    // getUserInput(&ROW, &COL, &randomize);
    int arr[ROW][COL];
    // fill and print array
    fill2DArray(ROW, COL, arr, randomize);
    print2DArray(ROW, COL, arr);

    // print max of array
    printf("Max of array: %d\n", max(ROW, COL, arr));

    // print sums of rows
    for (int i = 0; i < ROW; i++) {
        
    }
    
}

void fill2DArray(int row, int col, int arr[row][col], bool randomize) {
    if (randomize) {
        // uncomment this for random initialization
        // srand(time(NULL));
        int min = 0, max = 100;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[i][j] = rand() % (max - min + 1) + min;
            }
        }
    } else {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("Enter item index [%d][%d]: ", i, j);
                int s;
                scanf("%d", &s);
                arr[i][j] = s;
            }
        }
    }
}

void print2DArray(int row, int col, int arr[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0) {
                printf("[%d, ", arr[i][j]);
            } else if (j == col - 1) {
                printf("%d]\n", arr[i][j]);
            } else
            printf("%d, ", arr[i][j]);
        }
    }
}

void getUserInput(int* row, int* col, bool* randomize) {
    printf("%s", "How many rows? ");
    int i;
    scanf("%d", &i);
    *row = i;

    printf("%s", "How many columns? ");
    int j;
    scanf("%d", &j);
    *col = j;

    printf("%s", "Should the array be filled randomly? (y/n) ");
    char c;
    scanf(" %c", &c);
    if (c == 'y' || c == 'Y') {
        *randomize = true;
    } else {
        *randomize = false;
    }
}

int max(int row, int col, int arr[row][col]) {
    int max = INT_MIN;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}