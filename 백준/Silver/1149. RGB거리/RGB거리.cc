#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cost[1010][3];
int N;
int arr[1010][3];

void go() {
	for (int i = 1; i <= N; i++) {
		arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + cost[i][0];
		arr[i][1] = min(arr[i - 1][2], arr[i - 1][0]) + cost[i][1];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + cost[i][2];
	}
}

int main(void) {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	go();

	printf("%d", min({ arr[N][0], arr[N][1], arr[N][2]}));

	return 0;
}