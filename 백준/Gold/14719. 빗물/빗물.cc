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

int H, W;
bool block[510][510];
int ans = 0;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		int x;
		cin >> x;
		for (int j = H - 1; j >= H - x; j--) {
			block[j][i] = 1;
		}
	}

	int temp = 0;
	bool isBlockedLine = false;
	for (int j = H - 1; j >= 0; j--) {
		for (int i = 0; i < W; i++) {
			if (block[j][i] == 1) {
				isBlockedLine = true;
			}
			if (isBlockedLine && block[j][i] == 0) {
				temp++;
			}
			else if (isBlockedLine&& block[j][i] == 1 && temp != 0) {
				ans += temp;
				temp = 0;
			}
		}
		isBlockedLine = false;
		temp = 0;
	}

	cout << ans;

	return 0;
}