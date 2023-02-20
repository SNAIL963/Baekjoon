#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int factorial(int num) {
	if (num == 0) return 1;
	else
		return num * factorial(num - 1);
}
int main() {
	int num;
	scanf("%d", &num);

	printf("%d", factorial(num));
    return 0;
}