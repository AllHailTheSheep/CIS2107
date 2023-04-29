#include "lab9.h"

#include <stdio.h>

int main() {
    printf("%s\n", "Beginning all_letters test.");
    char* str = "Test";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
    str = "Test.";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
    str = "Test ";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
    str = "T3st";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
    str = "QuiteABitLongerOfATestSentence";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));

    
}