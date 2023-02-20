#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dp[1000500];

void go() {
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
}

int main(void) {
	scanf("%d", &N);

	go();
	printf("%d", dp[N]);

	return 0;
}