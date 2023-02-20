#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n;
int dp[12];

void go() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
}
int main(void) {
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		go();
		printf("%d\n", dp[n]);
	}

	return 0;
}