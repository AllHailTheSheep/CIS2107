#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

void summarize(int, int);
void executeHareMove(int, int*);
void executeTortMove(int, int*);
bool isWithinRange(int, int, int);
int pickIntRandomly(int, int);


#define END 70
#define SLEEP_TIME .1

int main() {
    // print begin message
    printf("%s\n", "BANG!\nAND THEY'RE OFF!");
    // seed random number generator
    srand(time(NULL));
    // set hare and tort positions to 1, and define pointers to them
    int hare = 1;
    int tort = 1;
    int* tortp;
    int* harep;
    tortp = &tort;
    harep = &hare;
    // set sentinel value
    bool done = false;
    while (!done) {
        // move tort
        int tortMove = pickIntRandomly(1, 10);
        executeTortMove(tortMove, tortp);

        // move hare
        int hareMove = pickIntRandomly(1, 10);
        executeHareMove(hareMove, harep);

        // summarize
        summarize(tort, hare);

        // check end conditions
        if (tort == END) {
            printf("%s\n", "TORTOISE WINS! YAY!");
            done = true;
        } else if (hare == END) {
            printf("%s\n", "Hare wins. Yuch.");
            done = true;
        }
        sleep(SLEEP_TIME);
    }
    return EXIT_SUCCESS;
}

/**
 * Summarizes the race so far. Prints "OUCH" if the tortoise and hare are in the same position.
 * @p tort the tortoise's position.
 * @p hare the hare's position.
*/
void summarize(int tort, int hare) {
    // define an array of chars the size of the END position + 1 (for sentinel and newline chars)
    char base[END + 1];
    // fill the arr with spaces
    for (int i = 0; i < END; i++) {
        base[i] = ' ';
    }
    // set the end position (must be done before setting the tort and hare positions in case they are at the end)
    base[END - 1] = 'E';
    // if tort pos == hare pos, set that pos to O, else set both tort and hare positions. note the minus 1 because th
    // positoins are not using zero based indexing
    if (tort == hare) {
        base[tort - 1] = 'O';
    } else {
        base[tort - 1] = 'T';
        base[hare - 1] = 'H';
    }
    // set newline and terminal characters
    base[END] = '\n';
    base[END + 1] = '\0';

    // iterate through the array printing each character, unless the char is O, in which case we need to print OUCH
    for (int i = 0; i <= END + 2; i++) {
        if (base[i] == 'O') {
            printf("%s", "OUCH");
        } else {
            printf("%c", base[i]);
        }
    }
}

/**
 * Moves according to the hare ruleset.
 * @p move the move selected (between 1 and 10 inclusive).
 * @p pos a pointer to the hare's position.
*/
void executeHareMove(int move, int* pos) {
    // 1-2: sleep
    if (isWithinRange(move, 1, 2)) {
        return;
    }

    // 3-4: 9 sqaures right
    if (isWithinRange(move, 3, 4)) {
        *pos += 9;
    }

    // 5: 12 sqaures left
    if (move == 5) {
        *pos -= 12;
    }

    // 6-8 : 1 sqaure right
    if (isWithinRange(move, 6, 8)) {
        *pos += 1;
    }

    // 9-10 : 2 sqaures left
    if (isWithinRange(move, 9, 10)) {
        *pos -= 2;
    }

    // check pos is within 1 - END
    if (*pos < 1) {
        *pos = 1;
    } else if (*pos > END) {
        *pos = END;
    }

}

/**
 * Moves according to the tortoise ruleset.
 * @p move the move selected (between 1 and 10 inclusive).
 * @p pos a pointer to the tortoise's position.
*/
void executeTortMove(int move, int* pos) {
    // 1-5: 3 squares right
    if (isWithinRange(move, 1, 5)) {
        *pos += 3;
    }

    // 6-7: 6 sqaures left
    if (isWithinRange(move, 6, 7)) {
        *pos -= 6;
    }

    // 8-10: 1 square left
    if (isWithinRange(move, 8, 10)) {
        *pos += 1;
    }

    // check pos is within 1 - END
    if (*pos < 1) {
        *pos = 1;
    } else if (*pos > END) {
        *pos = END;
    }
}

/**
 * Returns true if the given int is between the min and max values (inclusive).
 * @p n the number to check.
 * @p min the minimum value acceptable.
 * @p the the maximum value acceptable.
 * @return true if the given int is between the min and max values, else false.
*/
bool isWithinRange(int n, int min, int max) {
    // swap min and max if needed
    if (min > max) {
        int swp = min;
        min = max;
        max = swp;
    }

    // check if n is within range
    if (min <= n && n <= max) {
        return true;
    }
    return false;
}

/**
 * Picks an integer between the min and max values (inclusive).
 * @p min the minimum value to choose.
 * @p max the maximum value to choose.
 * @return the integer chosen.
*/
int pickIntRandomly(int min, int max) {
    return rand() % (max - min + 1) + min;
}