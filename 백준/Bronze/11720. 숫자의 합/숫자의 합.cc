#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int size;
	scanf("%d", &size);
	char num[101];
	scanf("%s", num);
	int sum = 0;

	for (int i = 0; i < size; i++)
		sum += num[i] - 48;
	printf("%d", sum);
}