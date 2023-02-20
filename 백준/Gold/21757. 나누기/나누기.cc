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
#define inf 100000000001

int N;
int arr[100100];
long long sum[100100];
long long dp[100100][4];

int main(void) {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	//부분합 저장
	sum[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		sum[i] += sum[i - 1] + arr[i];
	}

	long long num = sum[N] / 4;

	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 3; j++) {
			dp[i][j] = dp[i - 1][j];
			if (sum[i] == num * j) dp[i][j] += dp[i - 1][j - 1];
		}
	}

	if (sum[N] % 4) printf("0");
	else printf("%lld", dp[N][3]);

	return 0;
}