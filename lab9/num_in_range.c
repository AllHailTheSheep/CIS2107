#include "lab9.h"

// returns the num of characters such that b<=c<=t. the bounds must be the same case, but an upper case letter can be between two lower case letters.
int num_in_range(char *s, int b, int t) {
    int res = 0;
    while (*s != '\0') {
        if ((*s >= b && t >= *s) || ((*s >= convert_case(b) && convert_case(t) >= *s))) {
            res++;
        }
        s++;
    }
    return res;
}