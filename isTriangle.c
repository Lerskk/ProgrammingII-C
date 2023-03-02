#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int max(int numberA, int numberB, int numberC) {
	if (numberA < numberB) {
		if (numberB < numberC)
			return 2;
		return 1;
	}
	if (numberA < numberC)
		return 2;
	return 0;
}

bool isTriangle(int sideA, int sideB, int sideC) {
	switch (max(sideA, sideB, sideC)) {
		case 0:
			return ((sideB + sideC) < sideA);
		case 1:
			return ((sideA + sideC) < sideB);
		case 2:
			return ((sideA + sideB) < sideC);
	}
}

bool compare(int sideA, int sideB, int sideC) {
	return ((pow(sideA, 2) + pow(sideB, 2)) == pow(sideC, 2));
}

bool isRight(int sideA, int sideB, int sideC) {
	switch (max(sideA, sideB, sideC)) {
		case 0:
			return compare(sideB, sideC, sideA);
		case 1:
			return compare(sideA, sideC, sideB);
		case 2:
			return compare(sideA, sideB, sideC);
	}
}

int main() {
	printf("%b", isTriangle(1, 2, 4));
	printf("%b", isTriangle(4, 2, 1));
	printf("%b", isTriangle(2, 4, 1));
	printf("%b", isTriangle(1, 1, 1));
	printf("%b", isRight(1, 1, 1));
	printf("%b", isRight(3, 4, 5));
	printf("%b", isRight(5, 13, 12));
	printf("%b", isRight(7, 3, 5));
	return 0;
}