#include <stdio.h>
#include <stdlib.h>

int getInt(char*, char*);
double getDouble(char*, char*);
void calculate(int, double, double);

const char* line = "=====================================";

int main() {
	printf("%s\n\n", "Welcome to \"TEMPLE HUMAN RESOURCES\"");
	int eID = getInt("Enter Employee ID: ", "This is not a valid Employee Number.\nPlease run the program again.");
	double hourly = getDouble("Enter Hourly Salary: ", "This is not a valid hourly salary amount.\nPlease run the program again.");
	double weekly = getDouble("Enter Weekly Hours: ", "This is not a weekly time.\nPlease run the program again.");
	calculate(eID, hourly, weekly);
	printf("\n%s", "Thank you for using \"TEMPLE HUMAN RESOURCES\"");
	return EXIT_SUCCESS;
}

double getDouble(char* prompt, char* onFail) {
	double i;
	printf(prompt);
	scanf("%f", &i);
	if (i <= 0) {
		printf("\n%s\n", onFail);
		return EXIT_FAILURE;
	}
	return i;
}

int getInt(char* prompt, char* onFail) {
	int i;
	printf(prompt);
	scanf("%d", &i);
	if (i <= 0) {
		printf("\n%s\n", onFail);
		return EXIT_FAILURE;
	}
	return i;
}

void calculate(int eID, double hourly, double weekly) {
	printf("%s\n", line);
	printf("Employee #: %d\n", eID);
	printf("Hourly Salary: $%.2f\n", hourly);
	printf("Weekly Time: %.2f\n", weekly);
	double regular, overtime, net;
	regular = weekly > 40 ? hourly * 40 : weekly * hourly;
	
	overtime = weekly > 40 ? (weekly - 40) * (1.5 * hourly) : 0;
	net = regular + overtime;
	printf("Regular Pay: $%.2f\n", regular);
	printf("Overtime: $%.2f\n", overtime);
	printf("Net Pay: $%.2f\n", net);
	printf("%s\n", line);	
}