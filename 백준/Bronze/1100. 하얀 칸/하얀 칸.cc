#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	char chess[9][8];
	int count = 0;

	for (int i = 0; i < 8; i++) {
		scanf("%s", chess[i]);
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0 && chess[i][j] == 'F')
				count += 1;
		}
	}
	printf("%d", count);
}