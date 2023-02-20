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
#define MAX 101000

using namespace std;

int V, E;
int parent[MAX];
long long result = 0;
priority_queue <pair <int, pair<int, int>>> pq;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;

	if (x < y) parent[y] = x;
	else parent[x] = y;
}
bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return true;
	else return false;
}
void kruskal() {
	while (!pq.empty()) {
		int u, v, w;
		u = -pq.top().first;
		v = find(pq.top().second.first);
		w = find(pq.top().second.second);
		pq.pop();
		if (v != w) {
			result += u;
			Union(v, w);
		}
	}
	return;
}
int main(void) {
	long long ThisSum = 0;
	bool connected = true;
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		ThisSum += w;
		pq.push({ -w,{u,v} });
	}
	
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	
	kruskal();
	
	for (int i = 1; i <= V; i++) {
		int x = parent[1];
		if (find(i) != x) {
			connected = false;
			break;
		}
	}
	if (connected) printf("%lld", ThisSum - result);
	else printf("-1");

	return 0;
}