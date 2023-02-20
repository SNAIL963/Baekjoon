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
#define inf 1000000000

using namespace std;

int v, e;
int arr[505][505];

void floyd() {
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}
int main(void) {
	scanf("%d %d", &v, &e);

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			arr[i][j] = inf;
		}
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[a - 1][b - 1] = min(arr[a - 1][b - 1], c);
	}
	floyd();

	int ans = inf;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (i == j) {
				ans = min(ans, arr[i][j]);
			}
		}
	}
	if (ans == inf)
		printf("-1");
	else printf("%d", ans);

	return 0;
}