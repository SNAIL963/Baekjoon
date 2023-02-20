#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int N, M, V;
int a, b; // 사람
vector <int> adj[1100];
int cnt = 0;
int chonsu[1100];
queue <int> q;

void bfs(int start) {
	chonsu[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == b)
			break;
		int x = adj[now].size();
		for (int i = 0; i < x; i++) {
			int next = adj[now][i];
			if (chonsu[next] == 0) {
				chonsu[next] = chonsu[now] + 1;
				q.push(next);
			}
		}
	}
}
int main(void) {
	scanf("%d", &N);
	scanf("%d %d", &a, &b);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	bfs(a);

	if (chonsu[b] == 0)
		printf("-1");
	else
		printf("%d", chonsu[b]);

	return 0;
}
