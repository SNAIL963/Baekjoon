#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int r, c;
long long ans = 0;

void go(int row, int col, int size) {  // r = a, c = b는 현재 첫번째지점 좌표
	if (size == 1)
		return;
	if (r < row + size / 2 && c < col + size / 2) {
		go(row, col, size / 2);
	}
	else if (r < row + size / 2 && c >= col + size / 2) {
		ans += (long long)size * size * 1 / 4;
		go(row, col + size / 2, size / 2);
	}
	else if (r >= row + size / 2 && c < col + size / 2) {
		ans += (long long)size * size * 2 / 4;
		go(row + size / 2, col, size / 2);
	}
	else if (r >= row + size / 2 && c >= col + size / 2) {
		ans += (long long)size * size * 3 / 4;
		go(row + size / 2, col + size / 2, size / 2);
	}
}
int main(void) {
	scanf("%d %d %d", &N, &r, &c);

	go(0, 0, (int)pow(2, N));

	printf("%lld", ans);
	return 0;
}