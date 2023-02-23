#include <stdio.h>
#include <stdlib.h>

double getDouble(char*, char*);
int getInt(char*, char*);
void calculate(double, int);

int main() {
    printf("%s\n", "Welcome to \"TEMPLE\" store");
    double price = getDouble("\tEnter item price: ", "\tThat is not a valid item price.\n\tPlease run the program again.");
    int quantity = getInt("\tEnter quantity: ", "\tThat is not a valid item quantity order.\n\tPlease run the program again.");
    printf("%s\n", "");
    calculate(price, quantity);
    printf("%s\n", "Thank You for using \"TEMPLE\" store");
    return EXIT_SUCCESS;
}

void calculate(double price, int quantity) {
    double cost, discount, discountAmount, total;
    cost = price * quantity;
    if (quantity < 50) {
        discount = 0;
    } else if (quantity < 100) {
        discount = .1;
    } else if (quantity < 150) {
        discount = .15;
    } else if (quantity >= 150) {
        discount = .25;
    }
    discountAmount = discount * cost;
    total = cost - discountAmount;
    printf("\tThe item price is: $%.2f\n", price);
    printf("\tThe order is: %d item(s)\n", quantity);
    printf("\tThe cost is: $%.2f\n", cost);
    printf("\tThe discount is: %.2f%%\n", discount * 100);
    printf("\tThe discount amount is: $%.2f\n", discountAmount);
    printf("\tThe total is: $%.2f\n\n", total);
    return;
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
