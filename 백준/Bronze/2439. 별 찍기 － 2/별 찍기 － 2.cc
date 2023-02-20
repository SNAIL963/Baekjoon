#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int line;
	scanf("%d", &line);

	for (int i = 0; i < line; i++) {
		for (int j = i; j < line-1; j++) {
			printf(" ");
		}
		for (int k = 0; k < i+1; k++) {
			printf("*");
		}
		printf("\n");
	}
}