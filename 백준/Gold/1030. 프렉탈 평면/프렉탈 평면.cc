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

// 제일처음 가장 큰 사각형에서 가운데 사각형에 포함되는지 확인
// 두번째로 큰 사각형에서 가운데에 포함되는지 확인
// 사각형의 크기가 1이 된다면 흰색 반환, 가운데 포함되면 검은색 반환

int s, N, K, R1, R2, C1, C2;

int go(int y, int x, int size) {
	if (size == 1) return 0;
	int ns = size / N;
	if (x >= ns * (N - K) / 2 && x < ns * (N + K) / 2 &&
		y >= ns * (N - K) / 2 && y < ns * (N + K) / 2) 
		return 1;
	return go(y % ns, x % ns, ns);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	if (s == 0) {
		cout << 0;
	}
	else {
		int startSize = (int)pow(N, s);

		for (int i = R1; i <= R2; i++) {
			for (int j = C1; j <= C2; j++) {
				cout << go(i, j, startSize);
			}
			cout << endl;
		}
	}
	return 0;
}