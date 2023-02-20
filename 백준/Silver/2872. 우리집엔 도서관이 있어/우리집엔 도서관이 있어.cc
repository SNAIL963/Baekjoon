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
int N;
int cnt = 0;
vector <int> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int tmp = N;
	for (int i = N - 1; i >= 0; i--) {
		if (v[i] == tmp) {
			cnt++;
			tmp--;
		}
	}

	cout << N - cnt;

	return 0;
}