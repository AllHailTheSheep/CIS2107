#include "lab9.h"

// returns the length of s1 - s2
int len_diff(char *s1, char * s2) {
    int l1 = 0;
    int l2 = 0;
    while (s1[l1] != '\0') l1++;
    while (s2[l2] != '\0') l2++;
    return l1 - l2;
}