#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#define max 100000

using namespace std;
int n, m;
int arr[110][110];
int visited[110][110];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue <pair <int, int>> q;
int hour = 0;
int cnt = 0;
int cntemp = 0;

void dfs(int sy,int sx) {
	cnt = 0;
	hour++;
	visited[sy][sx] = 1;
	q.push(make_pair(sy, sx));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[ny][nx] == 0) {
				if (arr[ny][nx] == 0) {
					visited[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
				else {
					arr[ny][nx] = 0;
					visited[ny][nx] = 1;
					cnt++;
				}
			}
		}
	}
	if (cnt == 0) return;
	else cntemp = cnt;
}
int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	while (1) {
		dfs(0, 0);
		if (cnt == 0) {
			printf("%d\n", hour-1);
			printf("%d", cntemp);
			break;
		}
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}