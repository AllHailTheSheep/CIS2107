#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double getDouble(char*, char*);
int getPIN(char*, char*);
int getIntR(char*, char*);
void printOptions();
int getIntAndValidate(char*, char*, int*, size_t);

int  OPTIONS[4] = {1, 2, 3, 4};
int const MAX_FAILS = 3;

int main() {
    int pin;
    bool QUIT;
    QUIT = false;
    pin = getInt("Enter your PIN: ", "Not a valid PIN.");
    while (!QUIT) {
        printOptions();
        int option = getInt("Choose an option: ", "Not a valid option.");
        printf("%d\n", option);
        // TODO: switch statement instead of ifs
        if (option == 4) {
            QUIT = true;
        }
    }
    return EXIT_SUCCESS;

}

int getOption() {
    int fails = 0;
    return -1;
}

int getPIN(char* prompt, char* onFail) {
    int fails = 0;
    while (fails < MAX_FAILS) {
        int res = getIntR(prompt, onFail);
        if (res < 0) {
            fails++;
        } else {
            return res;
        }
    }
    printf("%d", "To many failures. Please try again.");
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
