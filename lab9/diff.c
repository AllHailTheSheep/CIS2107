#include "lab9.h"
#include <stdio.h>
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
// returns the amount of moves (substitutions, insertions, deletions) that would make the string equal.
int diff(char *s1, char *s2) {
    // we are going to be using an adaptation of the Levenshtein distance algorithm. for more info see https://en.wikipedia.org/wiki/Levenshtein_distance.
    // a lot of this implementation is borrowed from https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C
    // we will need to find the size of each string
    int l1 = 0;
    int l2 = 0;
    while(s1[l1] != '\0') l1++;
    while(s2[l2] != '\0') l2++;

    // initialize with max moves for each step
    int arr[l1 + 1];
    for (int i = 1; i <= l1; i++) {
        arr[i] = i;
    }

    // we save the last calculations, this way we can use a 1d array instead of a 2d array
    int last;
    int old;

    // iterae through s2
    for (int j = 1; j <= l2; j++) {
        // this would be min number of moves to make and empty s1 into s2
        arr[0] = j;
        // iterate through s1
        for (int i = 1, last = j - 1; i <= l1; i++) {
            old = arr[i];
            // we want the smallest of insert (current element + 1), delete (prev element + 1), and substite (prev element + 1 if if current s1 is diff then s2. else 0)
            arr[i] = MIN3(arr[i] + 1, arr[i - 1] + 1, last + (s1[i-1] == s2[j - 1] ? 0 : 1));
            last = old;
        }
    }
    return arr[l1];
}