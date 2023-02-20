#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[130][130];
int blue = 0;
int white = 0;

void div(int x, int y, int size) {    // x, y가 시작좌표
	int first = arr[x][y];

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (first != arr[i][j]) {
				div(x, y, size / 2);
				div(x, y + (size / 2), size / 2);
				div(x + (size / 2), y, size / 2);
				div(x + (size / 2), y + (size / 2), size / 2);
				return;
			}
		}
	}

	if (first == 1) blue++;
	else white++;
}

int main(void) {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	div(0, 0, num);

	printf("%d\n%d", white, blue);

	return 0;
}