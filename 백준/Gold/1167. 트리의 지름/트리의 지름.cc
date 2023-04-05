#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#define MAX 100100

using namespace std;

vector <pair <int, int>> edge[MAX];
int a, n;
int visited[MAX];
int maxValue;

// 임의의 점을 골라서
// 그 점에서 가장 먼 정점 a를 구하고
// 또 그 점에서 가장 먼 정점 까지의 거리를 구하면 그게 최장 경로
void DFS(int node, int length) {
	if (visited[node]) {
		return;
	}
	visited[node] = 1;
	if (maxValue < length) {
		maxValue = length;
		a = node;
	}
	int x = edge[node].size();
	for (int i = 0; i < x; i++) {
		int nextNode = edge[node][i].first;
		int nextValue = edge[node][i].second;
		DFS(nextNode, length + nextValue);
	}
	return;
}
int main(void) {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		;	while (true) {
			int b, c;
			scanf("%d", &b);
			if (b == -1) break;
			scanf("%d", &c);

			edge[a].push_back({ b,c });
		}
	}

	DFS(1, 0);

	memset(visited, 0, sizeof(visited));
	maxValue = 0;

	DFS(a, 0);

	printf("%d\n", maxValue);

	return 0;
}