#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double getDouble(char*, char*);
int getPIN();
int getOption();
int getIntR(char*, char*);
void printOptions();
int getIntAndValidate(char*, char*, int*, size_t);

int  OPTIONS[4] = {1, 2, 3, 4};
int const MAX_FAILS = 3;

int main() {
    int pin;
    bool QUIT;
    QUIT = false;
    pin = getPIN();
    while (!QUIT) {
        printOptions();
        int option = getOption();
        printf("%d\n", option);
        // TODO: switch statement instead of ifs
        if (option == 4) {
            QUIT = true;
        }
    }
    return EXIT_SUCCESS;

}

int getOption() {
    char* prompt = "Choose an option: "; 
    char* onFail = "Not a valid option.";
    int fails = 0;
    return -1;
}

int getPIN() {
    char* prompt = "Enter your PIN: ";
    char* onFail = "Not a valid PIN.";
    int fails = 0;
    while (fails < MAX_FAILS) {
        int res = getIntR(prompt, onFail);
        if (res <= 0) {
            printf("%s\n", onFail);
            fails++;
        } else {
            return res;
        }
    }
    printf("%s\n", "To many failures. Please try again.");
    exit(EXIT_FAILURE);
}

int getIntR(char* prompt, char* onFail) {
	double i;
	printf("%s", prompt);
	scanf("%lf", &i);
	if (i != (int)i) {
		printf("\n%s\n", onFail);
		return -1;
	}
	return (int)i;
}

void printOptions() {
    printf("%s\n%s\n%s\n%s\n", "1. Balance", "2. Cash Withdrawal", "3. Cash Deposit", "4. Quit");
}
