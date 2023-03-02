#include <stdio.h>

int max(int numberOne, int numberTwo) {
	if (numberOne < numberTwo)
		return numberTwo; 
	return numberOne;
}

int main() {
	int a, b, c, d;
	printf("insert 4 number to get the max between them\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	printf("%d", max(max(a, b), max(c, d)));
	return 0;
}