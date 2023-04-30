#include "lab9.h"

// shortens the length of s to new_len. if new_len>sizeof(s), there is no change
void shorten(char *s, int new_len) {
    int l = 0;
    while(s[l] != '\0') l++;
    if (new_len < l) {
        s[new_len] = '\0';
    }
    return;
}