#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int n;
long long dp[10][66];
long long ans;

void go() {
	ans = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			long long x = 0;
			for (int k = 0; k <= j; k++) {
				x += dp[k][i - 1];
			}
			dp[j][i] = x;
		}
	}
	for (int i = 0; i < 10; i++) {
		ans += dp[i][n];
	}
}
int main(void) {
	scanf("%d", &T);

	for (int i = 0; i < 10; i++) {
		dp[i][1] = 1;
	}

	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		go();
		printf("%lld\n", ans);
	}

	return 0;
}