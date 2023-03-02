#include <stdio.h>

int zodiacSign(int day, int month) {
	if ((22 < day && month == 12) || (day < 20 && month == 1)) {
		printf("capricorn\n");
		return 0;
	}
	printf("some other one lol\n");
	return 0;
}

int main() {
	zodiacSign(22, 12);
	zodiacSign(23, 12);
	zodiacSign(31, 12);
	zodiacSign(10, 1);
	zodiacSign(30, 1);
	return 0;
}