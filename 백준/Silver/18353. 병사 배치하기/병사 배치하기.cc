#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[2020];
int dp[2020];  
int n;

int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	reverse(arr, arr + n);

	fill_n(dp, n, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int maxValue = 0;

	for (int i = 0; i < n; i++)
		maxValue = max(maxValue, dp[i]);
	
	printf("%d", n - maxValue);   // 제거한 숫자의 개수

	return 0;
}