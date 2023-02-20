#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int* ptr) {
	if (*ptr == 1) {
		*ptr = 0;
	}
	else if (*ptr == 0) {
		*ptr = 1;
	}
}
int main() {
	int num_switch;
	scanf("%d", &num_switch);

	int arr[100];

	for (int i = 0; i < num_switch; i++) {
		scanf("%d", &arr[i]);
	}

	int num_student;
	scanf("%d", &num_student);

	for (int i = 0; i < num_student; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (x == 1) {
			for (int j = y; j <= num_switch; j += y) {
				swap(&arr[j - 1]);
			}
		}
		else if (x == 2) {
			swap(&arr[y - 1]);
			int a = y - 1;
			int b = y - 1;
			while (arr[a] == arr[b]) {
				swap(&arr[a]);
				swap(&arr[b]);
				if (a > 0 && b < num_switch - 1) {
					a--;
					b++;
				}
				else break;
			}
		}
	}
	int a = 0;
	while (a < num_switch) {
		printf("%d ", arr[a]);
		if ((a + 1) % 20 == 0)
			printf("\n");
		a++;
	}

	return 0;
}