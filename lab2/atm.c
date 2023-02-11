#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double getDouble(char*, char*);
int getPIN();
int getOption();
int getInt(char*, char*);
void printOptions();
int getIntAndValidate(char*, char*, int*, size_t);

int  OPTIONS[4] = {1, 2, 3, 4};
char* const LINE = "--------------------";
int const MAX_FAILS = 3;

int main() {
    bool QUIT = false;
    double balance = 0.0;
    int actionscount = 0;
    int actions[32];
    int pin = getPIN();
    while (!QUIT) {
        printOptions();
        int option = getOption();
        printf("%d\n", option);
        switch (option) {
        case 1: ;
            // balance
            printf("%s\nBalance: %.2f\n%s\n", LINE, balance, LINE);
            actions[actionscount++] = 1;
            break;
        case 2: ;
            // cash withdrawal
            actions[actionscount++] = 2;
            break;
        case 3: ;
            // cash deposit
            actions[actionscount++] = 3;
            break;
        case 4: ;
            // quit
            int i;
            for(i = 1; i < actionscount - 1; i++) {
                printf("%d\n", actions[i]);
            }
            QUIT = true;
            break;
        }
    }
    return EXIT_SUCCESS;
}

int getOption() {
    char* prompt = "Choose an option: "; 
    char* onFail = "Not a valid option.";
    while (true) {
        int res = getInt(prompt, onFail);
        if (!(res == 1 || res == 2 || res == 3 || res == 4)) {
            printf("%s\n", onFail);
        } else {
            return res;
        }
    }
}

int getPIN() {
    char* prompt = "Enter your PIN: ";
    char* onFail = "Not a valid PIN.";
    int fails = 0;
    while (fails < MAX_FAILS) {
        int res = getInt(prompt, onFail);
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

int getInt(char* prompt, char* onFail) {
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
