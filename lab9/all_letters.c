#include "lab9.h"

// returns 1 if all chars in s are letters, 0 otherwise.
int all_letters(char *s) {
    // iterate through the string until we hit the terminator char
    while (*s != '\0') {
        // if a is greater than or equal to a and less than or equal to c, it is a letter. we must check capitals seperately since we cannot use isAlpha
        if (!((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))) {
            return 0;
        }
        s++;
    }
    // if we iterated through the string without returning 0 already it must be all letters
    return 1;
}