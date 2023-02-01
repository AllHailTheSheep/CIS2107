#include <stdio.h>
#include <stdlib.h>

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
	int i;
	printf("%s", prompt);
	scanf("%d", &i);
	if (i <= 0) {
		printf("\n%s\n", onFail);
		exit(EXIT_FAILURE);
	}
	return i;
}