#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[115][115];
long long dp[115][115];
int n;

void go() {
	dp[1][1] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] >= 1) {
				if (i == n && j == n) continue;
				dp[i + arr[i][j]][j] += dp[i][j];
				dp[i][j + arr[i][j]] += dp[i][j];
			}
		}
	}
}
int main(void) {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	go();

	printf("%lld", dp[n][n]);

	return 0;
}