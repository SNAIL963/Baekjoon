#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int size;
	scanf("%d", &size);
	int* grade = (int*) malloc(sizeof(int) * size);
	double average = 0.0;

	for (int i = 0; i < size; i++) {
		scanf("%d", &grade[i]);
	}
	
	int highest=grade[0];

	for (int i = 0; i < size; i++) {
		if (grade[i] > highest)
			highest = grade[i];
	}
	
	for (int i = 0; i < size; i++) {
		average += ((double) (grade[i] * 100) / highest) / size;
	}
	printf("%f\n", average);
}