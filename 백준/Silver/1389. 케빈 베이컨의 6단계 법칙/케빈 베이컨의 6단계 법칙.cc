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

int n, m;
int arr[105][105];


void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}
int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(i==j) arr[i][j] = 0;
			else arr[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	floyd();
	int answer = 0;
	int minSum = inf;
	for (int i = 1; i <= n; i++) {
		int thisSum = 0;
		for (int j = 1; j <= n; j++) {
			thisSum += arr[i][j];
		}
		if (minSum > thisSum) {
			answer = i;
			minSum = min(thisSum, minSum);
		}
	}

	printf("%d", answer);

	return 0;
}