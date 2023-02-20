#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int K;
int x, y;
int arr[150][150];
int cnt = 1;

// empty라면 넘어간다
bool isEmpty(int sy, int sx, int size) {
	for (int i = sy; i < sy + size; i++) {
		for (int j = sx; j < sx + size; j++) {
			if (arr[i][j] != 0) return true;
		}
	}
	return false;
}

void go(int sy, int sx, int size) {
	if (size == 1) return;
	int ns = size / 2;
	if (!isEmpty(sy, sx, ns)) arr[sy + ns - 1][sx + ns - 1] = cnt;
	if (!isEmpty(sy + ns, sx, ns)) arr[sy + ns][sx + ns - 1] = cnt;
	if (!isEmpty(sy, sx + ns, ns)) arr[sy + ns - 1][sx + ns] = cnt;
	if (!isEmpty(sy + ns, sx + ns, ns)) arr[sy + ns][sx + ns] = cnt;
	cnt++;
	go(sy, sx, ns);
	go(sy + ns, sx, ns);
	go(sy, sx + ns, ns);
	go(sy + ns, sx + ns, ns);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	cin >> x >> y;

	int startSize = (int)pow(2, K);
	int nx, ny;
	nx = startSize - 1;
	ny = startSize - 1;
	arr[ny - (y - 1)][x - 1] = -1;

	go(0, 0, startSize);

	for (int i = 0; i < startSize; i++) {
		for (int j = 0; j < startSize; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}