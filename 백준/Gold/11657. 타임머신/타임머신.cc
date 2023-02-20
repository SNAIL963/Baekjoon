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

long long dist[550];
int N, M;
vector <pair <int, int>> edge[550];
bool cycle = 0;

void Bellman_Ford() {
	dist[1] = 0;
	int next = 0;
	int nextcost = 0;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				next = edge[i][j].first;
				nextcost = edge[i][j].second;
				if (dist[i] != inf && dist[next] > dist[i] + nextcost) {
					dist[next] = dist[i] + nextcost;
					if (k == N) cycle = 1;
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++) {
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		edge[s].push_back({ e,c });
	}

	fill(&dist[1], &dist[N+1], inf);

	Bellman_Ford();

	if (cycle == 1)
		printf("-1\n");
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == inf)	printf("-1\n");
			else printf("%lld\n", dist[i]);
		}
	}

	return 0;
}