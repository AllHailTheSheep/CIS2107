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
    printf("Input string: \"%s\". new_len: %d. Output: %s.\n", "\"Tester\"", 4, strArr);
    char strArr1[32] = "Test Part 2 (the sequel)";
    shorten(strArr1, 32);
    printf("Input string: \"%s\". new_len: %d. Output: %s.\n", "\"Test Part 2 (the sequel)\"", 11, strArr1);
    shorten(strArr1, 32);
    printf("Input string: \"%s\". new_len: %d. Output: %s.\n", "\"Test Part 2\"", 11, strArr1);
    shorten(strArr1, 32);
    printf("Input string: \"%s\". new_len: %d. Output: %s.\n", "\"Test Part 2\"", 15, strArr1);

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
    char strArr2[32] = " Test ";
    rm_left_space(strArr2);
    printf("Input string: \"%s\". Output: \"%s\".\n", " Test", strArr2);
    char strArr3[32] = "\n Test ";
    rm_left_space(strArr3);
    printf("Input string: \"%s\". Output: \"%s\".\n", "\\n Test ", strArr3);
    char strArr4[32] = "\n \t . testing . ";
    rm_left_space(strArr4);
    printf("Input string: \"%s\". Output: \"%s\".\n", "\\n \\t . testing . ", strArr4);

    // TODO: this not working
    printf("\n%s\n", "Beginning rm_right_space() test.");
    char strArr5[32] = " Test ";
    rm_right_space(strArr5);
    printf("Input string: \"%s\". Output: \"%s\".\n", " Test ", strArr5);
    char strArr6[32] = " test";
    rm_right_space(strArr6);
    printf("Input string: \"%s\". Output: \"%s\".\n", " test", strArr6);

    printf("\n%s\n", "Beginning rm_space() test.");
    char strArr7[32] = " Test ";
    rm_space(strArr7);
    printf("Input string: \"%s\". Output: \"%s\".\n", " Test ", strArr7);
    char strArr8[32] = " \n\tTest";
    rm_space(strArr8);
    printf("Input string: \"%s\". Output: \"%s\".\n", " \\n\\tTest", strArr8);

    printf("\n%s\n", "Beginning find() test.");
    str = "Test";
    str1 = "st";
    printf("Haystack: \"%s\". Needle: \"%s\". Output: %d.\n", str, str1, find(str, str1));
    str = "Testing functions is necessary, but will eventually drive me insane.";
    str1 = "ll";
    printf("Haystack: \"%s\". Needle: \"%s\". Output: %d.\n", str, str1, find(str, str1));
    str1 = "y";
    printf("Haystack: \"%s\". Needle: \"%s\". Output: %d.\n", str, str1, find(str, str1));
    str1 = "e.";
    printf("Haystack: \"%s\". Needle: \"%s\". Output: %d.\n", str, str1, find(str, str1));

    printf("\n%s\n", "Beginning find() test.");
    str = "Test";
    str1 = "st";
    printf("Haystack: \"%s\". Needle: \"%s\". Output: %p.\n", str, str1, ptr_to(str, str1));
    str = "Testing functions is necessary, but will eventually drive me insane.";
    str1 = "ll";
    printf("Haystack: \"%s\". Needle: \"%s\". Output: %p.\n", str, str1, ptr_to(str, str1));
    str1 = "y";
    printf("Haystack: \"%s\". Needle: \"%s\". Output: %p.\n", str, str1, ptr_to(str, str1));
    str1 = "e.";
    printf("Haystack: \"%s\". Needle: \"%s\". Output: %p.\n", str, str1, ptr_to(str, str1));

    printf("\n%s\n", "Beginning is_empty() test.");
    str = "test";
    printf("Input string: \"%s\". Output: %d.\n", "test", is_empty(str));
    str = "\0";
    printf("Input string: \"%s\". Output: %d.\n", "\\0", is_empty(str));
    str = " \n a\t ";
    printf("Input string: \"%s\". Output: %d.\n", " \\n a\\t ", is_empty(str));
    str = " \n \t \t \0";
    printf("Input string: \"%s\". Output: %d.\n", " \\n \\t \\t \\0", is_empty(str));
    str = NULL;
    str = " \n \t ";
    printf("Input string: %s. Output: %d.\n", "NULL", is_empty(str));

    printf("\n%s\n", "Beginning str_zipchar() test.");
    str = "Test";
    str1 = "Test";
    printf("s1: \"%s\". s2: \"%s\". Output: \"%s\".\n", str, str1, str_zipchar(str, str1));
    str = "Apples";
    str1 = "Oranges";
    printf("s1: \"%s\". s2: \"%s\". Output: \"%s\".\n", str, str1, str_zipchar(str, str1));
    str = "Spongebob";
    str1 = "Patrick";
    printf("s1: \"%s\". s2: \"%s\". Output: \"%s\".\n", str, str1, str_zipchar(str, str1));

    printf("\n%s\n", "Beginning capitalize() test.");
    char strArr9[64] = "testing Functions iS important.";
    capitalize(strArr9);
    printf("Input string: \"%s\". Output: \"%s\".\n", "testing Functions iS important.", strArr9);
    char strArr10[64] = "Testing Functions iS STILL important.";
    capitalize(strArr10);
    printf("Input string: \"%s\". Output: \"%s\".\n", "Testing Functions iS STILL important.", strArr10);

    printf("\n%s\n", "Beginning strcmp_ign_case() test.");
    str = "Before";
    str1 = "After";
    printf("s1: \"%s\". s2: \"%s\". Output: %d.\n", str, str1, strcmp_ign_case(str, str1));
    str = "After";
    str1 = "before";
    printf("s1: \"%s\". s2: \"%s\". Output: %d.\n", str, str1, strcmp_ign_case(str, str1));
    str = "Equal";
    str1 = "equal";
    printf("s1: \"%s\". s2: \"%s\". Output: %d.\n", str, str1, strcmp_ign_case(str, str1));

    printf("\n%s\n", "Beginning take_last() test.");
    char strArr11[64] = "Test";
    take_last(strArr11, 3);
    printf("s: \"%s\". n: %d. Output: \"%s\".\n", "Test", 3, strArr11);
    char strArr12[64] = "This function seems to be working!";
    take_last(strArr12, 8);
    printf("s: \"%s\". n: %d. Output: \"%s\".\n", "This function seems to be working!", 8, strArr12);

    printf("\n%s\n", "Beginning dedup() test.");
    str = "Test";
    printf("s1: \"%s\". Output: \"%s\".\n", str, dedup(str));
    str = "No Duplicates";
    printf("s1: \"%s\". Output: \"%s\".\n", str, dedup(str));
    str = "This string contains some duplicates.";
    printf("s1: \"%s\". Output: \"%s\".\n", str, dedup(str));

    
}