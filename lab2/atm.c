#include <stdio.h>
#include <stdlib.h>

double getDouble(char*, char*);
double getDoubleR(char*, char*, int);
int getInt(char*, char*);
int getIntR(char*, char*, int);

int main() {
    int pin;
    pin = getInt("Enter your PIN: ", "Not a valid PIN.");
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
        printf("%s\n", "Too many attempt. Exiting..\n");
        exit(EXIT_FAILURE);
    }
	return i;
}
