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
#define max 100000

using namespace std;
int n, m;
int arr[310][310];
int visited[310][310];
int check[310][310];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue <pair <int, int>> q;
int hour = 0;
int numIce = 0;
int cnt = 0;
bool ismeltAll = 0;

void dfs(int sy,int sx) {
	visited[sy][sx] = 1;
	q.push(make_pair(sy, sx));
	cnt = 1;
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
					cnt++;
				}
				else {
					arr[ny][nx] = arr[ny][nx] - 1;
					if(arr[ny][nx] == 0)
						visited[ny][nx] = 1;
				}
			}
		}
	}
	if (cnt == n * m)
		ismeltAll = true;
}
void checktwo(int sy, int sx) {
	numIce++;
	check[sy][sx] = 1;
	q.push(make_pair(sy, sx));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && check[ny][nx] == 0 && !arr[ny][nx] == 0) {
					check[ny][nx] = 1;
					q.push(make_pair(ny, nx));
			}
		}
	}
}
int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0 && !visited[i][j]) {
					dfs(i, j);
				}
			}
		}
		hour++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!arr[i][j] == 0 && !check[i][j]) {
					checktwo(i, j);
				}
			}
			if (numIce > 1) break;
		}
		if (numIce > 1) {
			printf("%d", hour);
			break;
		}
		else if (ismeltAll == true) {
			printf("0");
			break;
		}
		memset(visited, 0, sizeof(visited));
		memset(check, 0, sizeof(check));
		numIce = 0;
	}

	return 0;
}