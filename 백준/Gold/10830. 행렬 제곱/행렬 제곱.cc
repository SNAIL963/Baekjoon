#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

long long N, B;
long long ans[6][6], matrix[6][6];

void go(long long a[6][6], long long b[6][6]) {
	long long temp[5][5] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				temp[i][j] += (a[i][k] * b[k][j]);
				temp[i][j] %= 1000;
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = temp[i][j];
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
		ans[i][i] = 1;

	}
	while (B > 0) {
		if (B % 2)go(ans, matrix);
		go(matrix, matrix);
		B /= 2;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
