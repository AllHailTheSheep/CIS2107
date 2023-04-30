#include "lab9.h"
#include <stdio.h>

int main() {
    printf("%s\n", "Beginning convert_case() test (a helper function I wrote).");
    printf("Input char: \"%c\". Output: %c.\n", 'c', convert_case('c'));
    printf("Input char: \"%c\". Output: %c.\n", 'V', convert_case('V'));
    printf("Input char: \"%c\". Output: %c.\n", 'Z', convert_case('Z'));

    printf("\n%s\n", "Beginning all_letters() test.");
    char* str = "Test";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
    str = "Test.";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
    str = "Test ";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
    str = "T3st";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));
    str = "QuiteABitLongerOfATestSentence";
    printf("Input string: \"%s\". Output: %d.\n", str, all_letters(str));

    printf("\n%s\n", "Beginning num_in_range() test.");
    str = "Test";
    printf("Input string: \"%s\". Bounds: \'a\', \'z\'. Output: %d.\n", str, num_in_range(str, 'a', 'z'));
    printf("Input string: \"%s\". Bounds: \'A\', \'Z\'. Output: %d.\n", str, num_in_range(str, 'A', 'Z'));
    printf("Input string: \"%s\". Bounds: \'a\', \'f\'. Output: %d.\n", str, num_in_range(str, 'a', 'f'));
    str = "QuiteABitLongerOfATestSentence";
    printf("Input string: \"%s\". Bounds: \'a\', \'f\'. Output: %d.\n", str, num_in_range(str, 'a', 'f'));

    printf("\n%s\n", "Beginning diff() test.");
    str = "Test";
    char* str1 = "test";
    printf("Input strings: \"%s\", \"%s\". Output: %d.\n", str, str1, diff(str, str1));
    str = "Tester";
    str1 = "test";
    printf("Input strings: \"%s\", \"%s\". Output: %d.\n", str, str1, diff(str, str1));
    str = "Not Even Close";
    str1 = "kinda close?";
    printf("Input strings: \"%s\", \"%s\". Output: %d.\n", str, str1, diff(str, str1));

    printf("\n%s\n", "Beginning shorten() test.");
    char strArr[6] = "Tester";
    shorten(strArr, 4);
    printf("Input string: \"%s\". new_len: %d. Output: %s.\n", "Tester", 4, strArr);
    char strArr1[24] = "Test Part 2 (the sequel)";
    shorten(strArr1, 11);
    printf("Input string: \"%s\". new_len: %d. Output: %s.\n", "Test Part 2 (the sequel)", 11, strArr1);
    shorten(strArr1, 11);
    printf("Input string: \"%s\". new_len: %d. Output: %s.\n", "Test Part 2", 11, strArr1);
    shorten(strArr1, 15);
    printf("Input string: \"%s\". new_len: %d. Output: %s.\n", "Test Part 2", 15, strArr1);

    printf("\n%s\n", "Beginning len_diff() test.");
    str = "Test";
    str1 = "Tester";
    printf("Input strings: \"%s\", \"%s\". Output: %d.\n", str, str1, len_diff(str, str1));
    str = "Tester";
    str1 = "Test";
    printf("Input strings: \"%s\", \"%s\". Output: %d.\n", str, str1, len_diff(str, str1));
    str = "Testing with punctuaion!!";
    str1 = "This is still a test...";
    printf("Input strings: \"%s\", \"%s\". Output: %d.\n", str, str1, len_diff(str, str1));

    printf("\n%s\n", "Beginning rm_left_space() test.");
    char strArr2[5] = " Test";
    rm_left_space(strArr2);
    printf("Input string: \"%s\". Output: %s.\n", " Test", strArr2);
    char strArr3[7] = "\n Test ";
    rm_left_space(strArr3);
    printf("Input string: \"%s\". Output: %s.\n", "\\n Test ", strArr3);
}