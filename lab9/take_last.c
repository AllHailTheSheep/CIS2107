#include "lab9.h"


// modifies s so that it only consists of the last n characters
void take_last(char *s, int n) {
    int sl = 0;
    while (s[sl] != '\0') sl++;
    if (n >= sl) {
        return;
    }
    char * last = &s[sl - n];
    for (int i = 0; i < n; i++) {
        s[i] = last[i];
    }
    s[n] = '\0';
    return;
}