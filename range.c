#include <stdio.h>

int printRange(int start, int end) {
	if (end < start) {
		printf("The end: %d is greater than the start: %d\n", end, start);
		return 1;
	}
	for (int counter = start; counter <= end; counter++) 
		printf("%d\n", counter);
	return 0;
}

void dynamicRange() {
	int start, end;
	printf("Start of range: ");
	scanf("%d", &start);
	printf("End of range: ");
	scanf("%d", &end);
	printRange(start, end);
}

int main() {
	printRange(20, 30);
	printRange(80, 80);
	printRange(21, 20);
	dynamicRange();
	return 0;
}