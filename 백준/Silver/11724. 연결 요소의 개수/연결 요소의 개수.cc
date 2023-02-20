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
int cnt = 0;
bool visited_dfs[1100];
queue <int> q;

void dfs(int now) {	
	visited_dfs[now] = 1;
	int x = adj[now].size();
	for (int i = 0; i < x; i++) {
		int next = adj[now][i];
		if (!visited_dfs[next]) {
			visited_dfs[next] = 1;
			dfs(next);
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	
	for (int i = 1; i <= N; i++) {
		if (visited_dfs[i] == 0) {
			dfs(i);
			cnt++;
			continue;
		}
	}
	printf("%d", cnt);

	return 0;
}