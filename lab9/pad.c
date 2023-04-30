#include "lab9.h"
#include <stdlib.h>

// returns a new string based on s but padded by spaces at the end so that total length of new string is an even multiple of d.
// if it already is, returns a copy of the string. returns null on fail or if s is null
char * pad(char *s, int d) {
    if (s == NULL) {
        return NULL;
    }
    int sl = 0;
    while (s[sl] != '\0') sl++;

    if (sl % d == 0) {
        char *dest;
        char *d = dest;
        while (sl--) *d++ = *s++;
        return dest;
    }
}