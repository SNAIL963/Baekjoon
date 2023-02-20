#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int line;
	scanf("%d", &line);

	for (int i = 0; i < line; i++) {
		for (int j = i; j < line; j++) {
			printf("*");
		}
		printf("\n");
	}
}