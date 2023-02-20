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
#define MAX 1050

using namespace std;

int K, num;
vector<int> v;
vector<int> level[20];

void search(int s, int e, int depth) {
	if (s == e) {
		level[depth].push_back(v[s]);
		return;
	}
	int mid = (e + s) / 2;
	level[depth].push_back(v[mid]);
	search(s, mid - 1, depth + 1);
	search(mid + 1, e, depth + 1);
}

int main(void) {
	cin >> K;
	
	for (int i = 0; i < pow(2, K) - 1; i++) {
		cin >> num;
		v.push_back(num);
	}
	search(0, v.size() - 1, 0);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < level[i].size(); j++) {
			cout << level[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}