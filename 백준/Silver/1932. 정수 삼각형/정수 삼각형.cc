#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[500][500];
int dp[500][500];
int ans;
int num;

void tri() {

	for (int i = num; i >= 1; i--) {
		for (int j = i; j >= 1; j--) {
			arr[i - 1][j] += max(arr[i][j], arr[i][j + 1]);
		}
	}

	return;
}

int main(void) {
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	tri();

	printf("%d", arr[1][1]);
	
	return 0;
}