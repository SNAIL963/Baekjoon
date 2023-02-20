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
#define MAX 1000100


int parent[MAX];
int n, m;

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return;

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

void Check(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) printf("YES\n");
	else printf("NO\n");
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			Union(b, c);
		}
		else {
			Check(b, c);
		}
	}

	return 0;
}