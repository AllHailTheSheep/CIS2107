#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_COL 32

void fill2DArray(int row, int col, int[][MAX_COL], bool rand);
void print2DArray(int row, int col, int[][MAX_COL]);
void getUserInput(int*, int*, bool*);

int main() {
    // TODO: take user input for row and col
    int ROW = 3;
    int COL = 3;
    bool randomize = true;
    getUserInput(&ROW, &COL, &randomize);
    // int arr[ROW][COL];
    // fill2DArray(ROW, COL, arr, true);
    // print2DArray(ROW, COL, arr);
    
}

void fill2DArray(int row, int col, int arr[row][MAX_COL], bool randomize) {
    if (randomize) {
        // uncomment this for random initialization
        // srand(time(NULL));
        int min = 0, max = 100;
        for (int i = 0; i <= row; i++) {
            for (int j = 0; j <= col; j++) {
                arr[i][j] = rand() % (max - min + 1) + min;
            }
        }
    }
}

void print2DArray(int row, int col, int arr[row][MAX_COL]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0) {
                printf("[%d, ", arr[j][i]);
            } else if (j == col - 1) {
                printf("%d]\n", arr[j][i]);
            } else
            printf("%d, ", arr[j][i]);
        }
    }
}

void getUserInput(int* row, int* col, bool* randomize) {
    printf("%s", "How many rows? ");
    int i = 0;
    scanf("%d", &i);
    *row = i;

    printf("%s", "How many columns? ");
    int j = 0;
    scanf("%d", &j);
    *col = j;

    printf("%s", "Should the array be filled randomly? (y/n) ");
    char c;
    scanf("%c", &c);
    if (c == 'y' || c == 'Y') {
        *randomize = true;
    } else {
        *randomize = false;
    }
}