#include "lab9.h"

//  compares to words ignoring case. returns positive if s1 appears after s2 in dict, negative if not, 0 if equal
int strcmp_ign_case(char *s1, char *s2) {
    int s1l = 0;
    int s2l = 0;
    while (s1[s1l] != '\0') s1l++;
    while (s2[s2l] != '\0') s2l++;

    int i, j;
    for (i = 0, j = 0; i < s1l, j < s2l; i++, j++) {
        char a, b;
        if (s1[i] >= 'A' && s1[i] <= 'Z') {
            a = convert_case(s1[i]);
        } else {
            a = s1[i];
        }
        if (s2[j] >= 'A' && s2[j] <= 'Z') {
            b = convert_case(s2[j]);
        } else {
            b = s2[j];
        }
        if (a > b) {
            return 1;
        } else if (a < b) {
            return -1;
        }
    }
    return 0;
}