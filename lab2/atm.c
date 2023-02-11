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
int const MAX_FAILS = 3;

int main() {
    bool QUIT = false;
    double balance = 0.0;
    int actionscount = 0;
    char** actions = malloc(sizeof(char*)*6);
    int pin = getPIN();
    while (!QUIT) {
        printOptions();
        int option = getOption();
        printf("%d\n", option);
        // TODO: switch sta
        switch (option) {
        case 1:
            // balance
            printf("Balance: %f\n", balance);
            sprintf(actions[actionscount++], "Balance: %f", balance);
            break;
        case 2:
            // cash withdrawal
            break;
        case 3:
            // cash deposit
            break;
        case 4:
            // quit
            for(int i = 0; i < actionscount; i++) {
                printf("%s\n", actions[i]);
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
    int fails = 0;
    while (true) {
        int res = getIntR(prompt, onFail);
        if (res != 1 || res != 2 || res != 3 || res != 4 || res == NULL) {
            printf("%s\n", onFail);
            fails++;
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
        int res = getIntR(prompt, onFail);
        if (res <= 0 || res == NULL) {
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
		return NULL;
	}
	return (int)i;
}

void printOptions() {
    printf("%s\n%s\n%s\n%s\n", "1. Balance", "2. Cash Withdrawal", "3. Cash Deposit", "4. Quit");
}
