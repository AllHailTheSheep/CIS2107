#include "lab9.h"
#include <stdlib.h>

char * str_zipchar (char *s1, char *s2) {
    int s1l = 0;
    int s2l = 0;
    while (s1[s1l] != '\0') s1l++;
    while (s2[s2l] != '\0') s2l++;

    char * res = malloc((s1l + s2l + 1) * sizeof(char));
    // i is iterator, j is for keeping track of progress through s1, k is for s2
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < s1l + s2l; i++) {
        if (i % 2 == 0 && j < s1l) {
            res[i] = s1[j];
            j++;
        } else if (k < s2l) {
            res[i] = s2[k];
            k++;
        }
    }
    res[s1l + s2l + 1] = '\0';
    return res;
}