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
#define inf 100000000001

using namespace std;

int N, M;
int vision[101000];
vector <pair <int, int>> v[101000];

void djk() {
	vector <long long> dist(N, inf);
	dist[0] = 0;
	priority_queue <pair< long long, int >> pq; // 거리, 향하는곳

	pq.push({ 0,0 });

	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			int ncost = v[here][i].second;

			if (dist[next] > dist[here] + ncost && vision[next] == 0) {
				dist[next] = dist[here] + ncost;
				pq.push({ -dist[next],next });
			}
		}

	}
	if (dist[N - 1] == inf) printf("-1");
	else printf("%lld", dist[N - 1]);
}
int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &vision[i]);
	}

	vision[N - 1] = 0;

	for (int i = 0; i < M; i++) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		v[a].push_back({ b,t });
		v[b].push_back({ a,t });
	}

	djk();

	return 0;
}