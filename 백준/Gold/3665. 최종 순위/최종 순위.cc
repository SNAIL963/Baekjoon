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
#define MAX 550

using namespace std;

int tc, n, m;
bool adj[MAX][MAX];
int inDegree[MAX];
int ranking[MAX];
vector <int> first_in;

queue <int> q;
vector <int> ans;
bool impossible = false;

void init() {
	memset(adj, 0, sizeof(adj));
	memset(inDegree, 0, sizeof(inDegree));
	memset(ranking, 0, sizeof(ranking));
	first_in.clear();
	ans.clear();
	impossible = false;
}

void topologySort() {
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			ans.push_back(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			impossible = true;
			return;
		}
		int now = q.front();
		q.pop();
		for (int j = 1; j <= n; j++) {
			if (adj[now][j] == 1) {
				int next = j;
				if (--inDegree[next] == 0) {
					q.push(next);
					ans.push_back(next);
				}
			}
		}
	}
}

int main(void) {
	scanf("%d", &tc);

	for (int k = 0; k < tc; k++) {
		init();

		scanf("%d", &n);

		// 순위를 입력받는다.
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			first_in.push_back(x);
			ranking[x] = i;
		}
		// 입력받은 순위로 방향관계 표시한다.
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				adj[first_in[i]][first_in[j]] = true;
				inDegree[first_in[j]]++;
			}
		}

		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (ranking[x] < ranking[y]) swap(x, y);
			adj[y][x] = false;
			inDegree[x]--;
			adj[x][y] = true;
			inDegree[y]++;
		}

		topologySort();
		if (impossible == true) printf("IMPOSSIBLE\n");
		else {
			for (int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}