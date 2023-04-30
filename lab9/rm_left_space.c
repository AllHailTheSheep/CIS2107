#include "lab9.h"
#include <ctype.h>

// strips whitespace from the left of the string
void rm_left_space(char *s) {
    // first, find length of s and the pos of the first char
    int l = 0;
    int first_char = -1;
    while (s[l] != '\0') {
        if (!isspace(s[l]) && first_char == -1) {
            first_char = l;
        }
        l++;
    }
    // init res to proper size
    char res[l - first_char + 1];
    // loop through s, while we are not at the end we copy it into res
    int i = first_char;
    int r = 0;
    while (s[i] != '\0') {
        res[r++] = s[i++];
    }
    // add nul to res
    res[r] = '\0';
    
    // copy res into s (note this code is pretty much the exact implementation of memcpy())
    char *d = s;
    char *c = res;
    while (r-- + 1) *d++ = *c++;
}