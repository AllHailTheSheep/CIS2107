#include "lab9.h"
#include <ctype.h>

// strips whitespace from the right of the string
void rm_right_space(char *s) {
    // first, find length of s and the pos of the last char
    int l;
    while (s[l] != '\0') l++;
    int last_char = l - 1;
    while (isspace(s[last_char]) && last_char >= 0) {
        last_char--;
    }
    // if last char is l - 1 return, there is nothing to do
    if (last_char == l - 1) return;
    // init res char array
    char res[last_char + 1];
    // copy from 0 to last char into res
    for (int i = 0; i <= last_char; i++) {
        res[i] = s[i];
    }
    // give res nul value
    res[last_char + 1] = '\0';
    // printf("s len: %d. last_char: %d. size of res: %d\n", l, last_char, last_char + 1);
    // copy res into s (note this code is pretty much the exact implementation of memcpy())
    char *d = s;
    char *c = res;
    while (last_char--) *d++ = *c++;
}