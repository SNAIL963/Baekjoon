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
#define MAX 100100

using namespace std;

int power[MAX];
int parent[MAX];
int n, m;

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {  // 동맹
	x = Find(x);
	y = Find(y);
	if (x < y) {
		parent[y] = x;
		power[x] += power[y];
		power[y] = 0;
	}
	else {
		parent[x] = y;
		power[y] += power[x];
		power[x] = 0;
	}
}

void War(int x, int y) {  // 전쟁
	x = Find(x);
	y = Find(y);

	if (power[x] > power[y]) {
		power[x] -= power[y];
		power[y] = 0;
		parent[y] = x;
	}
	else if (power[x] < power[y]) {
		power[y] -= power[x];
		power[x] = 0;
		parent[x] = y;
	}
	else {
		power[x] = 0;
		power[y] = 0;
		parent[x] = 0;
		parent[y] = 0;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &power[i]);
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			Union(b, c);
		}
		else if (a == 2) {
			War(b, c);
		}
	}

	vector <int> ans;

	for (int i = 1; i <= n; i++) {
		if (power[i])
			ans.push_back(power[i]);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}