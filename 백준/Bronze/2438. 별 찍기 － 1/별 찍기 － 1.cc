#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int line;
	scanf("%d", &line);
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < i+1; j++)
			printf("*");
		printf("\n");
	}
}