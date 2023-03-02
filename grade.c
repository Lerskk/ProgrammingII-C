#include <stdio.h>

int gradeOne(int grade) {
	if (2 <= grade && grade <= 5) {
		printf("insufficient\n");
		return 1;
	}
	if (grade ==  6) {
		printf("sufficient\n");
		return 1;
	}
	if (grade == 7) {
		printf("good\n");
		return 1;
	}
	if (grade == 8) {
		printf("very good\n");
		return 1;
	}
	if (grade == 9) {
		printf("outstanding\n");
		return 1;
	}
	if (grade == 10) {
		printf("excellent\n");
		return 1;
	}
	printf("invalid value\n");
	return 0;
}

int main() {
	gradeOne(6);
	gradeOne(1);
	gradeOne(11);
	return 0;
}