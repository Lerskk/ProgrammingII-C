#include <stdio.h>

void oneToHundred() {
	int counter = 1; 
	while (counter <= 100) {
		printf("%d\n", counter);
		counter++;
	}
	for (int counter = 1; counter <= 100; counter++) 
		printf("%d\n", counter);
}

void oddNumbers() {
	for (int counter = 1; counter <= 100; counter += 2)
		printf("%d\n", counter);
}

int main() {
	2oneToHundred();
	oddNumbers();
	return 0;
}