#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int size;
	scanf("%d", &size);

	int* A = (int*)malloc(sizeof(int) * size);
	int* B = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		scanf("%d %d", &A[i], &B[i]);
	}
	for (int i = 0; i < size; i++) {
		printf("%d\n", A[i]+B[i]);
	}
    return 0;
}