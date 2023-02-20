#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int arr[32][32];
// N과 M을 받아서 M C N을 구현하기

int com(int m, int n) {
	if (n == 0 || m == n) {
		return arr[m][n] = 1;
	}
	else if (arr[m][n] != 0) {
		return arr[m][n];
	}
	else
		return arr[m][n] = com(m - 1, n) + com(m - 1, n - 1);
}
int main(void) {
	int T;
	int n, m;
	scanf("%d", &T);	

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &n, &m);
		printf("%d\n", com(m, n));
	}
	return 0;
}