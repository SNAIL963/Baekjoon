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
vector <int> adj[1100];
bool visited_dfs[1100];
bool visited_bfs[1100];
queue <int> q;

void dfs(int now) {	
	visited_dfs[now] = 1;
	printf("%d ", now);
	int a = adj[now].size();
	for (int i = 0; i < a; i++){
		int next = adj[now][i];
		if(!visited_dfs[next])dfs(next);
	}
}
void bfs(int st) {
	visited_bfs[st] = 1;
	q.push(st);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		int x = adj[now].size();
		for (int i = 0; i < x; i++) {
			int next = adj[now][i];
			if (!visited_bfs[next]) {
				visited_bfs[next] = 1;
				q.push(next);
			}
		}
	}
}
int main(void) {
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(V);
	printf("\n");
	bfs(V);
	return 0;
}