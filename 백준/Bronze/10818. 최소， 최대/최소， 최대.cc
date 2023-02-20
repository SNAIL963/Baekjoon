#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int size;
	scanf("%d", &size);
	int* num = (int *)malloc(sizeof(int)*size);
	
	for (int i = 0; i < size; i++) {  
		scanf("%d", &num[i]);
	}
	int max = num[0];
	int min = num[0];
	for (int i = 0; i < size; i++) {
		if (max > num[i])
			max = num[i];
		if (min < num[i])
			min = num[i];
	}
	printf("%d %d", max, min);

	free(num);
}