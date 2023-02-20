#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {	
	int size, x;
	int arr[10000];
	scanf("%d %d", &size, &x);

	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < size; i++) {
		if (arr[i] < x) 
			printf("%d ", arr[i]);
	}
}