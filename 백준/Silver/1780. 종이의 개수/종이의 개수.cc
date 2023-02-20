#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[2200][2200];
int N;
int mone, zero, one;

void go(int y, int x, int size) {
	if (size == 0)
		return;
	int a = arr[y][x];   // 시작지점 좌표

	for (int i = y; i < y+size; i++) {
		for (int j = x; j < x+size; j++) {
			if (a != arr[i][j]) {
				go(y, x, size / 3);
				go(y + size / 3, x, size / 3);
				go(y + size * 2 / 3, x, size / 3);
				go(y, x + size / 3, size / 3);
				go(y + size / 3, x + size / 3, size / 3);
				go(y + size * 2 / 3, x + size / 3, size / 3);
				go(y, x + size * 2 / 3, size / 3);
				go(y + size / 3, x + size * 2 / 3, size / 3);
				go(y + size * 2 / 3, x + size * 2 / 3, size / 3);
				return;
			}
		}
	}
	if (a == -1)
		mone++;
	else if (a == 0)
		zero++;
	else if (a == 1)
		one++;
}
int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	go(0, 0, N);
	printf("%d\n%d\n%d", mone, zero, one);
}