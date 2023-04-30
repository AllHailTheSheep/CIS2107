#include "lab9.h"
#include <ctype.h>

// modifies s so the first letter of each word is uppercase, all else are lowercase
void capitalize(char *s) {
    int sl = 0;
    while (s[sl] != '\0') sl++;
    for (int i = 0; i < sl; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (i - 1 < 0 || isspace(s[i - 1])) {
                s[i] = convert_case(s[i]);
            }
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            if (i - 1 > 0 && !isspace(s[i - 1])) {
                s[i] = convert_case(s[i]);
            }
        }
    }
}