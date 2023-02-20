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
#define inf 1000000000

using namespace std;
int N, M, K, X;
vector <int> adj[301000];
vector <int> dist;

void dijakstra(int s) {
	priority_queue <pair <int,int>> pq;
	dist.resize(N + 1, inf);
	dist[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			int nextcost = 1;

			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ -dist[next],next });
			}
		}
	}
}

int main(void) {
	scanf("%d %d %d %d", &N, &M, &K, &X);
	
	for (int i = 0; i < M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
	}

	dijakstra(X);
	
	bool check = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			printf("%d\n", i);
			if (check == 0)  check = 1;
		}
	}
	if (check == 0)
		printf("-1");

	return 0;
}