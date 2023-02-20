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
int cnt = 0;
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
int kruskal() {
	int result = 0;
	while (!pq.empty()) {
		if (cnt == V - 2) break;
		int u, v, w;
		u = -pq.top().first;
		v = find(pq.top().second.first);
		w = find(pq.top().second.second);
		pq.pop();
		if (v != w) {
			result += u;
			Union(v, w);
			cnt++;
		}
	}
	return result;
}
int main(void) {

	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		pq.push({ -w,{u,v} });
	}
	
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	printf("%d", kruskal());

	return 0;
}