#include "lab9.h"

char lower[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', '\0'};
char upper[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', '\0'};

// converts the case of a char or returns nul.
char convert_case(char c) {
    for (int i = 0; i < 27; i++) {
        if (c == lower[i]) {
            return upper[i];
        }
        if (c == upper[i]) {
            return lower[i];
        }
    }
    return '\0';
}