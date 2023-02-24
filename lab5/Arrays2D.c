#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

void fill2DArray(int*, int, int, bool);

const int ROW = 3;
const int COL = 3;

int main() {
    // TODO: take user input for row and col
    int arr[ROW][COL];
    int (*pointer)[ROW][COL];
    pointer = &arr;

    fill2DArray(pointer, ROW, COL, false);

    
}

void fill2DArray(int* arr, int row, int col, bool rand) {

}