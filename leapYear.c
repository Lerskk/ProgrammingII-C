#include <stdio.h>
#include <stdbool.h>

bool leapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

int main() {
	printf("%s\n", leapYear(2000) ? "true" : "false");
	printf("%s\n", leapYear(2002) ? "true" : "false");
	printf("%s\n", leapYear(1900) ? "true" : "false");
	return 0;
}