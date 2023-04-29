#include "lab9.h"

#include <stdio.h>

int main() {
    printf("%s\n", "Beginning all_letters test.");
    char* str = "This Is A Test";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
    str = "This Is A Test.";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
    str = "Th3s 15 4 T3ST.";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
}