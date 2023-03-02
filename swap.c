#include <stdio.h>

void swap(int *numberOne, int *numberTwo) {
	int temp = *numberOne;
	*numberOne = *numberTwo;
	*numberTwo = temp;
}
int main() {
	int c, d;
	int *a = &c, *b = &d; // pointer declaration
	*a = 10;
	*b = 5;
	printf("%p %p %d %d\n", &a, b, *a, *b);
	swap(a, b);
	printf("%p %p %d %d", &a, b, *a, *b);
	return 0;
}