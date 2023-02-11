#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getWithdrawalAmount();
int getOption();
int getPIN();
int getInt(char*, char*);
void printOptions();

int  OPTIONS[4] = {1, 2, 3, 4};
char* const LINE = "--------------------";
int const MAX_FAILS = 3;

int main() {
    bool QUIT = false;
    double balance = 50.0;
    int transactioncount = 0;
    int pin = getPIN();
    while (!QUIT) {
        printOptions();
        int option = getOption();
        switch (option) {
        case 1: ;
            // balance
            printf("%s\nBalance: %.2f\n%s\n", LINE, balance, LINE);
            break;
        case 2: ;
            // cash withdrawal
            int amt = getWithdrawalAmount(balance);
            transactioncount++;
            break;
        case 3: ;
            // cash deposit
            transactioncount++;
            break;
        case 4: ;
            // quit
            printf("Transaction count: %d\n", transactioncount);
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

int getWithdrawalAmount(double bal) {
    char* prompt = "Enter the amount to withdraw: ";
    char* onFail = "Withdwal amounts must be a multiple of 20, more than zero and less than the amount in your account.\nThere is a $1000/day limit.";
    int fails = 0;
    while (fails < MAX_FAILS) {
        int res = getInt(prompt, onFail);
        if (res <= 0 || res % 20 != 0 || res > bal) {
            printf("%s\n", onFail);
            fails++;
        } else {
            return res;
        }
    }
    printf("%s\n", "To many failures. Please try again.");
    exit(EXIT_FAILURE);
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
