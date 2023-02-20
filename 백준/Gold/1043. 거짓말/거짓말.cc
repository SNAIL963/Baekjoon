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
#define MAX 60

using namespace std;

int parent[MAX];
int n, m, k;

vector <int> know;
vector <vector<int>> v(55);

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	parent[x] = y;
}

int main(void) {
	scanf("%d %d", &n, &m);

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		know.push_back(x);
	}

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		int num;
		int prev;
		for (int j = 0; j < x; j++) {
			if (j >= 1) {
				prev = num;
				scanf("%d", &num);
				Union(prev, num);
			}
			else {
				scanf("%d", &num);
			}
			v[i].push_back(num);
		}
	}
	for (auto& i : v) {    // 행 이동
		bool check = false;
		for (auto& person : i) {    // 열 이동
			if (check) break;
			for (auto& t : know) {
				if (Find(person) == Find(t)) {
					check = true;
					break;
				}
			}
		}
		if (check) m--;
	}
	cout << m;
	return 0;
}