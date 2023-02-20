#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {	
	int testc;
	char str[81];

	scanf("%d", &testc);

	for (int i = 0; i < testc; i++) {
		scanf("%s", str);
		
		int score = 0;
		int size = 0;
		int stack = 0;
		
		for (int j = 0; str[j] != 0; j++)
			size++;

		for (int k = 0; k < size; k++) {
			if (str[k] == 'O') {
				stack++;
				score += stack;
			}
			else if (str[k] == 'X') {
				stack = 0;
			}
		}
		printf("%d\n", score);
	}
}