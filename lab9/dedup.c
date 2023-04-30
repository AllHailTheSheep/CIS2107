#include "lab9.h"
#include <stdlib.h>

// returns a new string based on s but containing no duplicate characters
char * dedup(char *s) {
    int sl = 0;
    while (s[sl] != '\0') sl++;
    char* res = (char*) malloc((sl + 1) * sizeof(char));
    // since we have ascii characters instead of a char array we will be simply using an int array so we can look up by index
    int arr[128] = {0};
    int i = 0, j = 0;
    while (s[i] != '\0') {
        char c = s[i];
        // if looking up char by its value is 0, then we havent seen the char. add that its been seen to the array and add the char to res
        if (!arr[c]) {
            arr[c] = 1;
            res[j++] = c;
        }
        i++;
    }
    // add nul to end of string
    res[j] = '\0'; 
    return res;
}