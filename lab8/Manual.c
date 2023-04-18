/*
 * Name:	Julia Fasick
 * Section:	003
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    printf("%s", "\n\n");
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\nNumber of words in string is: %d\n\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series, sizeof(series)/sizeof(series[0]));
    printf("%s", "\n");

    //test for endsWithed
    endsWithed(series, sizeof(series)/sizeof(series[0]));

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    int i = 0;
    while(s[i]) {
        printf("%c", toupper(s[i]));
        i++;
    }
    printf("%s", "\n");

    int j = 0;
    while(s[j]) {
        printf("%c", tolower(s[j]));
        j++;
    }
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    int sum = 0;
    sum += atoi(s1);
    sum += atoi(s2);
    sum += atoi(s3);
    sum += atoi(s4);
    return sum;
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    float sum = 0;
    sum += atof(s1);
    sum += atof(s2);
    sum += atof(s3);
    sum += atof(s4);
    return sum;
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    int i = strcmp(s1, s2);
    if (i < 0) {
        printf("%s is less than %s\n\n", s1, s2);
    } else if (i == 0) {
        printf("%s is equal to %s\n\n", s1, s2);
    } else if (i > 0) {
        printf("%s is greater than %s\n\n", s1, s2);
    }
    return;
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
    int i = strncmp(s1, s2, n);
    if (i < 0) {
        printf("%s is less than %s\n\n", s1, s2);
    } else if (i == 0) {
        printf("%s is equal to %s\n\n", s1, s2);
    } else if (i > 0) {
        printf("%s is greater than %s\n\n", s1, s2);
    }
    return;
}

//6.(Random Sentences) 
void randomize(void) {
    // this function could be improved by accounting for both nouns in the sentence,
    // and trying to make sure the verbs and articles make sense together.
    // seed random number generator
    srand(time(NULL));
    // declare arrays and their constant size
    int size = 5;
    char * articles[5] = {"the", "a", "one", "some", "any"};
    char * nouns[5] = {"boy", "girl", "dog", "town", "car"};
    char * verbs[5] = {"drove", "jumped", "ran", "walked", "skipped"};
    char * preps[5] = {"to", "from", "over", "under", "on"};
    char * sentences[20];
    char * last;
    // generate sentences according to this struture:
    // Article, noun, verb, prep, article, noun.
    // keep track of the last noun in the sentence, that is what we will use to attempt to make our story cohesive
    for (int i = 0; i < 20; i++) {
        char * sentence = (char *) malloc(256 * sizeof(char));
        char * first = articles[rand() % size];
        last = nouns[rand() % size];
        sprintf(sentence, "%c%s %s %s %s %s %s.", toupper(first[0]), first + 1, nouns[rand() % size],
                verbs[rand() % size], preps[rand() % size], articles[rand() % size], last);
        sentences[i] = sentence;
    }
    // declare story array
    char * story[5];
    // the first sentence of the story is the last sentence of the sentences
    story[0] = sentences[19];
    int storyct = 1;
    // if a sentence containse the last noun, then add it to our story and make sure it can't be repeated
    for (int i = 0; i < 20 && storyct < 5; i++) {
        if (strstr(sentences[i], last) != NULL) {
            story[storyct++] = sentences[i];
            sentences[i] = NULL;
        }
    }
    // print the story
    for (int i = 0; i < 5; i++) {
        printf("%s\n", story[i]);
    }
    // free the sentences that were allocated (note that nothing else was allocated)
    for (int i = 0; i < 20; i++) {
        free(sentences[i]);
    }
    return;
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
    // we will add each token to complete as we go, and then use that to get the number at the end
    char* tok;
    int areaCode;
    long number;
    char* complete;

    tok = strtok(num, "()");
    strcat(complete, tok);
    areaCode = atoi(tok);

    // use " -" so we dont have to deal with a space character
    tok = strtok(NULL, " -");
    strcat(complete, tok);

    tok = strtok(NULL, "-");
    strcat(complete, tok);

    char * numberStr = complete + strlen(complete) - 7;
    number = atof(numberStr);
    
    printf("\nArea Code: %d\n", areaCode);
    printf("Number: %ld\n", number);
    printf("Complete: %s\n\n", complete);
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    char * tok;
    char * toks[100];
    int tokct = 0;
    // collect all tokens to array
    tok = strtok(text, " ");
    while (tok != NULL) {
        toks[tokct++] = tok;
        tok = strtok(NULL, " ");
    }
    // print the array backwards
    for (int i = tokct - 1; i >= 0; i--) {
        printf("%s ", toks[i]);
    }
}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    int ct = 0;
    char * tok;
    // find first match
    tok = strstr(line, sub);
    while (tok != NULL) {
        ct++;
        // find next matches by passing current location + 1
        tok = strstr(tok + 1, sub);
    }
    return ct;
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    // i know the assignment says to use strchr but it is not necessary when c provides such incredible pointer access
    int ct = 0;
    // iterate through the line till there is nothing left, counting occurences of the char and then moving
    // the pointer one.
    while(*line) {
        if (toupper(*line) == toupper(c)) {
            ct++;
        }
        line++;
    }
    return ct;
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    // we are going to analyze a letter, put it in the charArr, then the count at the same index in the intArr.
    // this can be done since it is assured the index of the letter will be the index of the count in intArr.
    char charArr[26];
    int intArr[26] = {0};
    int indexed = 0;
    for (int i = 0; i < strlen(string); i++) {
        // if the char is alpha an is not already counted, add it
        if (isalpha(string[i]) && strchr(charArr, tolower(string[i])) == NULL) {
            charArr[indexed] = tolower(string[i]);
            intArr[indexed++] = countChar(string, string[i]);
        }
    }
    // summarize
    printf("%s\n", "character: occurences");
    for (int j = 0; j < indexed; j++) {
        printf("%c: %d\n", charArr[j], intArr[j]);
    }
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    int ct = 0;
    char * tok;
    tok = strtok(string, " \n");
    while (tok != NULL) {
        ct++;
        tok = strtok(NULL, " \n");
    }
    return ct;
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[], int size) {
    for (int i = 0; i < size; i++) {
        if (tolower(string[i][0]) == 'b') {
            printf("%s\n", string[i]);
        }
    }
}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[], int size) {
    for (int i = 0; i < size; i++) {
        int len = strlen(string[i]);
        if (tolower(string[i][len - 1]) == 'd') {
            printf("%s\n", string[i]);
        }
    }
}