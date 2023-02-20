#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	char str[5];
	int size=0;

	sprintf(str, "%d", N);

	for (int i = 0; str[i] != 0; i++) 
		size++;

	if (size * N <= M) {
		for (int j = 0; j < N; j++)
			printf("%s", str);
	}
	else {
		for (int k = 0; k < (M / size); k++)
			printf("%s", str);
		for (int l = 0; l < (M % size); l++)
			printf("%c", str[l]);
	}
}