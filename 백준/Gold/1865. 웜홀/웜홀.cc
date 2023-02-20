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

int dist[550];
int TC;
int N, M, W;
vector <pair <int, int>> edge[550];
bool cycle = 0;

void Bellman_Ford() {
	dist[1] = 0;
	cycle = 0;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				int next = edge[i][j].first;
				int nextcost = edge[i][j].second;
				if (dist[next] > dist[i] + nextcost) {
					dist[next] = dist[i] + nextcost;
					if (k == N) cycle = 1;
				}
			}
		}
	}
}

int main(void) {
	scanf("%d", &TC);
	for (int k = 0; k < TC; k++) {
		scanf("%d %d %d", &N, &M, &W);

		for (int i = 1; i <= M; i++) {
			int s, e, c;
			scanf("%d %d %d", &s, &e, &c);
			edge[s].push_back({ e,c });
			edge[e].push_back({ s,c });
		}
		for (int i = 1; i <= W; i++) {
			int s, e, c;
			scanf("%d %d %d", &s, &e, &c);
			edge[s].push_back({ e, -c });
		}

		fill(&dist[1], &dist[N + 1], inf);

		Bellman_Ford();

		if (cycle == 1)
			printf("YES\n");
		else
			printf("NO\n");

		for (int i = 1; i <= N; i++) {
			edge[i].clear();
		}
	}
	return 0;
}