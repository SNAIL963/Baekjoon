#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[1000100];

void go() {
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0 && i % 3 == 0)
			dp[i] = min({ dp[i - 1], dp[i / 2], dp[i / 3] }) + 1;
		else if (i % 2 == 0 && i % 3 != 0)
			dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
		else if (i % 2 != 0 && i % 3 == 0)
			dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
		else if (i % 2 != 0 && i % 3 != 0)
			dp[i] = dp[i - 1] + 1;
	}
}
int main(void) {
	scanf("%d", &n);

	go();

	printf("%d", dp[n]);

	return 0;
}