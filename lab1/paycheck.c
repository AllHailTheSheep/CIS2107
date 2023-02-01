#include <stdio.h>
#include <stdlib.h>

int getInt(char*, char*);
double getDouble(char*, char*);
void calculate(int, double, double);

const char* line = "=====================================";

int main() {
	printf("%s\n", "Welcome to \"TEMPLE HUMAN RESOURCES\"");
	int eID = getInt("\tEnter Employee ID: ", "\tThis is not a valid Employee Number.\n\tPlease run the program again.");
	double hourly = getDouble("\tEnter Hourly Salary: ", "\tThis is not a valid hourly salary amount.\n\tPlease run the program again.");
	double weekly = getDouble("\tEnter Weekly Hours: ", "\tThis is not a weekly time.\n\tPlease run the program again.");
	calculate(eID, hourly, weekly);
	printf("%s\n", "Thank you for using \"TEMPLE HUMAN RESOURCES\"");
	return EXIT_SUCCESS;
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

void calculate(int eID, double hourly, double weekly) {
	printf("\t%s\n", line);
	printf("\tEmployee #: %d\n", eID);
	printf("\tHourly Salary: $%.2f\n", hourly);
	printf("\tWeekly Time: %.2f\n", weekly);
	double regular, overtime, net;
	regular = weekly > 40 ? hourly * 40 : weekly * hourly;
	
	overtime = weekly > 40 ? (weekly - 40) * (1.5 * hourly) : 0;
	net = regular + overtime;
	printf("\tRegular Pay: $%.2f\n", regular);
	printf("\tOvertime: $%.2f\n", overtime);
	printf("\tNet Pay: $%.2f\n", net);
	printf("\t%s\n", line);	
}
