#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int num;
	scanf("%d", &num);
	int locate[81];
	char string[1000][81];

	for (int i = 0; i < num; i++) {
		scanf("%d %s", &locate[i], string[i]);
	}

	for (int i = 0; i < num; i++) {
		for (int j = locate[i] - 1; string[i][j] != 0; j++) {
			string[i][j] = string[i][j+1];
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%s\n", string[i]);
	}
}