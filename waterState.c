#include <stdio.h>

int waterState(int temperature) {
	if (temperature < 0) {
		printf("solid\n");
		return 1;
	}
	if (temperature < 100) {
		printf("liquid\n");
		return 1;
	}
	printf("gas\n");
	return 1;
}

int main() {
	waterState(-1);
	waterState(20);
	waterState(101);
	return 0;
}