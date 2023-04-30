#include "lab9.h"
#include <stdio.h>

char* ptr_to(char *h, char *n) {
    // get lengths of needle and haystack
    int hl = 0;
    int nl = 0;
    while (h[hl] != '\0') hl++;
    while (n[nl] != '\0') nl++;
    // iterate through haystack
    for (int i = 0; i < hl; i++) {
        // if a char in haystack matches the first char of needle, start a counter
        if (h[i] == n[0]) {
            int ct = 1;
            // iterate through needle to see if it is found in haystack
            for (int j = 1; j < nl; j++) {
                if (h[i + j] == n[j]) {
                    ct++;
                }
            }
            // if ct + 1 (we did not count the initial char) == nl then we found it, return the pointer to the index
            if (ct == nl) {
                return &h[i];
            }
        }
    }
    // we've iterated through the haystack without finding the needle
    return NULL;
}