#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double getDouble(char*, char*);
double getDoubleR(char*, char*, int);
int getInt(char*, char*);
int getIntR(char*, char*, int);
void printOptions();
int getIntAndValidate(char*, char*, int*, size_t);

int  OPTIONS[4] = {1, 2, 3, 4};

int main() {
    int pin;
    bool QUIT;
    QUIT = false;
    pin = getInt("Enter your PIN: ", "Not a valid PIN.");
    while (!QUIT) {
        printOptions();
        int option = getIntAndValidate("Choose an option: ", "", OPTIONS, 4);
        printf("%d\n", option);
        // TODO: switch statement instead of ifs
        if (option == 4) {
            QUIT = true;
        }
    }
    return EXIT_SUCCESS;

}

double getDouble(char* prompt, char* onFail) {
    getDoubleR(prompt, onFail, 0);
}

double getDoubleR(char* prompt, char* onFail, int fails) {
	double i;
	printf("%s", prompt);
	scanf("%lf", &i);
	if (i <= 0 && fails < 2) {
		printf("%s\n", onFail);
		i = getDoubleR(prompt, onFail, ++fails);
	}
    if (fails >= 3) {
        printf("%s\n", onFail);
        printf("%s\n", "Too may attempts. Exiting...\n");
        exit(EXIT_FAILURE);
    }
	return i;
}

int getIntAndValidate(char* prompt, char* onFail, int* valid, size_t size) {
    int res = getInt(prompt, onFail);
    bool flag = false;
    for (size_t i = 0; i < size; i++) {
        if (valid[i] == res) {
            flag = true;
        }
    }
    if (!flag) {
        res = getIntAndValidate(prompt, onFail);
    }
    return res;
}

int getInt(char *prompt, char* onFail) {
    return getIntR(prompt, onFail, 0);
}

int getIntR(char* prompt, char* onFail, int fails) {
	int i;
	printf("%s", prompt);
	scanf("%d", &i);
	if (i <= 0 && fails < 2) {
		printf("%s\n", onFail);
		i = getIntR(prompt, onFail, ++fails);
	}
    if (fails >= 3) {
        printf("%s\n", onFail);
        printf("%s\n", "Too many attempts. Exiting..\n");
        exit(EXIT_FAILURE);
    }
	return i;
}

void printOptions() {
    printf("%s\n%s\n%s\n%s\n", "1. Balance", "2. Cash Withdrawal", "3. Cash Deposit", "4. Quit");
}
