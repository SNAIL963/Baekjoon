#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp[100100] = { 0,3,7 };
int N;

int go(int N) {
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}
	return dp[N];
}
int main(void) {
	scanf("%d", &N);

	printf("%d", go(N));

	return 0;
}