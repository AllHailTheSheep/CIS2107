#include <stdio.h>
#include <stdlib.h>

double getDouble(char*, char*);
int getInt(char*, char*);

int main() {
    printf("%s\n", "Welcome to \"TEMPLE\" store");
    double price = getDouble("\tEnter item price: ", "\tThat is not a valid item price.\n\tPlease run the program again.");
    int quantity = getInt("\tEnter quantity: ", "\tThat is not a valid item quantity order.\n\tPlease run the program again.");

    printf("%.2f, %d\n", price, quantity);
    
}

double getDouble(char* prompt, char* onFail) {
	double i;
	printf("%s", prompt);
	scanf("%lf", &i);
	if (i <= 0) {
		printf("\n%s\n", onFail);
		exit(EXIT_FAILURE);
	}
	return i;
}

int getInt(char* prompt, char* onFail) {
	double i;
	printf("%s", prompt);
	scanf("%lf", &i);
	if (i <= 0 || i != (int)i) {
		printf("\n%s\n", onFail);
		exit(EXIT_FAILURE);
	}
	return (int)i;
}
