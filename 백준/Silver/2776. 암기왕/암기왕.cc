#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int T, N, M;
int arr[1000100];

int checkNum(int n) {
	int left = 0;
	int right = N - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (arr[middle] == n) {
			return 1;
		}
		else if (arr[middle] > n) {
			right = middle - 1;
		}
		else if (arr[middle] < n) {
			left = middle + 1;
		}
	}
	return 0;
}
int main(void) {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + N);

		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			int a;
			scanf("%d", &a);
			printf("%d\n", checkNum(a));
		}
	}
	return 0;
}