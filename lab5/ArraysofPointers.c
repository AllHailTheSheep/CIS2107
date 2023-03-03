#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void fill2DArray(int rows, int cols, int[][cols], bool);
void getUserInput(int*, int*, bool*);
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int main() {
    // default for variables i like using during testing
    int rows = 3;
    int cols = 4;
    bool randomize = true;
    // TODO: make sure this line is uncommented before submission!
    getUserInput(&rows, &cols, &randomize);
    int arr[rows][cols];
    // fill array
    fill2DArray(rows, cols, arr, randomize);
    void (*f[4])(int students, int exams, int grades[students][exams]) = {printArray, minimum, maximum, average};
    int choice = 0;
    while (true) {
        // if anythong other than a number is entered the while loop will run again but be unable to take more input
        // so assign choice to -1 so it will quit
        choice = -1;
        printf("%s\n", "0:  Print the array of grades\n1:  Find the minimum grade\n2:  Find the maximum grade\n3:  Print the average on all tests for each student\nAnything else:  End Program");
        scanf("%d", &choice);
        if (choice > -1 && choice < 4) {
            (*f[choice])(rows, cols, arr);
        } else {
            exit(EXIT_SUCCESS);
        }
        printf("%s", "\n");
    }
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
                printf("Enter grade for student %d exam %d: ", i, j);
                int s;
                scanf("%d", &s);
                arr[i][j] = s;
            }
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
    printf("%s", "How many students? ");
    int i;
    scanf("%d", &i);
    *rows = i;

    printf("%s", "How many exams? ");
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
 * Prints a 2d array.
 * @p rows the number of rows in the array.
 * @p cols the number of columns in the array.
 * @p arr the array to print
 * This function was taken from and barely modified from Arrays2D.c
*/
void printArray(int students, int exams, int grades[students][exams]) {
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            if (j == 0) {
                printf("[%d, ", grades[i][j]);
            } else if (j == exams - 1) {
                printf("%d]\n", grades[i][j]);
            } else
            printf("%d, ", grades[i][j]);
        }
    }
}

/**
 * Returns the min int that occurs in a 2d array.
 * @p rows the number of rows in the array.
 * @p cols the number of columns in the array.
 * @p arr the array to search.
 * @return the min int that occurs in the array.
 * This function was taken from and barely modified from Arrays2D.c
*/
void minimum(int students, int exams, int grades[students][exams]) {
    int min = INT_MAX;
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            if (grades[i][j] < min) {
                min = grades[i][j];
            }
        }
    }
    printf("Min of array: %d\n", min);
}

/**
 * Returns the max int that occurs in a 2d array.
 * @p rows the number of rows in the array.
 * @p cols the number of columns in the array.
 * @p arr the array to search.
 * @return the max int that occurs in the array.
 * This function was taken from and barely modified from Arrays2D.c
*/
void maximum(int students, int exams, int grades[students][exams]) {
    int max = INT_MIN;
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            if (grades[i][j] > max) {
                max = grades[i][j];
            }
        }
    }
    printf("Max of array: %d\n", max);
}

/**
 * Returns the average grade of the exams per student.
 * @p students the number of students.
 * @p exams the number of exams.
 * @p grades the array of grades by student and exam.
*/
void average(int students, int exams, int grades[students][exams]) {
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < exams; j++) {
            sum += grades[i][j];
        }
        printf("Student %d's average: %.2f\n", i, (double)sum/exams);
    }
}