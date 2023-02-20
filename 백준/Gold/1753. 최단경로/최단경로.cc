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
int N, M;           // N이 정점, M이 간선
vector <pair <int, int>> adj[20100];    // 인접 정점

void dijakstra(int start) {
	vector <int> dist(N + 1, inf);  // 거리를 저장할 벡터(무한대로 초기화)
	dist[start] = 0;                // 시작지점 거리 0으로 설정
	priority_queue <pair <int, int>> pq;  // -거리, 다음지점 
	pq.push({ 0,start });          // 우선순위 큐에 시작점을 넣음

	while (!pq.empty()) {
		int value = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < value) continue;
		int x = adj[here].size();
		for (int i = 0; i < x; i++) {
			int next = adj[here][i].first;
			int nextcost = adj[here][i].second;

			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ -dist[next],next });
			}
		}
	}

	for (int i = 1; i < N+1; i++) {
		if (dist[i] == inf)
			printf("INF\n");
		else printf("%d\n", dist[i]);
	}	
}

int main(void) {
	scanf("%d %d", &N, &M);
	
	int start;
	scanf("%d", &start);
	for (int i = 0; i < M; i++) {
		int s, e, v;
		scanf("%d %d %d", &s, &e, &v);
		adj[s].push_back({ e,v });
	}
		
	dijakstra(start);

	return 0;
}