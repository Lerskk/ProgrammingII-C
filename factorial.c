#include <stdio.h>

int factorial(int number) {
	if (number == 1) 
		return number;
	return number * factorial(number - 1);
}

int main() {
	printf("%d", factorial(10));
	return 0;
}

