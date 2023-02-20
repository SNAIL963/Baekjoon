#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long DP[100];

long long fib(int a) {
	DP[0] = 0;
	DP[1] = 1;

	for (int i = 2; i <= a; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	return DP[a];
}

int main(void) {
	int n;
	scanf("%d", &n);
	
	printf("%lld", fib(n));
	
	return 0;
}