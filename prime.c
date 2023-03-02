#include <stdio.h>
#include <stdbool.h>

bool isPrime() {
	int number;
	printf("Input a number to check if it's prime: ");
	scanf("%d", &number);

	for (int factors = 2; factors < number; factors++)
		if (number % factors == 0) 
			return false;
	return true;
}

int main() {
	printf("%b", isPrime());
	return 0;
}