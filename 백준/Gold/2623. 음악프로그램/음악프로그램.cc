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
#define MAX 100100

using namespace std;

vector <int> v[MAX];
int inDegree[MAX];
int N, M;
queue <int> q;

void topologySort() {
	vector <int> ans;

	for (int i = 1; i <= N; i++) {
		if (!inDegree[i]) {
			q.push(i);
			ans.push_back(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			if (--inDegree[v[now][i]] == 0) {
				q.push(v[now][i]);
				ans.push_back(v[now][i]);
			}
		}
	}

	if (ans.size() != N) {
		printf("0");
	}
	else {
		for (int i = 0; i < N; i++) {
			printf("%d\n", ans[i]);
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);

	vector <int> temp;
	for (int i = 1; i <= M; i++) {
		int a;
		scanf("%d", &a);
		
		temp.clear();
		for (int j = 0; j < a; j++) {
			int x;
			scanf("%d", &x);
			temp.push_back(x);
		}
		for (int k = 0; k < a-1; k++) {
			v[temp[k]].push_back(temp[k + 1]);
			inDegree[temp[k + 1]]++;
		}
	}
	topologySort();

	return 0;
}