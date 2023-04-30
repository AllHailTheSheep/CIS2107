#include "lab9.h"
#include <stdio.h>
#include <ctype.h>

int is_empty(char *s) {
    int sl = 0;
    while (s[sl] != '\0') sl++;
    int ct = 0;
    for (int i = 0; i < sl; i++) {
        if (isspace(s[i]) || s == NULL || s[i] == '\0') ct++;
    }
    if (ct == sl) {
        return 1;
    }
    return 0;
}