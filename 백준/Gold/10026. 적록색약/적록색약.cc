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
int N;
string arr[110];
queue <pair <int,int>> q;
int visited_n[110][110];
int visited_rg[110][110];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int cnt_rg = 0;
int cnt_n = 0;

void bfs_n(int sy, int sx, char s) {
	visited_n[sy][sx] = 1;
	q.push(make_pair(sy, sx));
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nexty = nowy + dy[i];
			int nextx = nowx + dx[i];
			if (nextx >= 0 && nextx < N && nexty >= 0 && nexty < N) {
				if (visited_n[nexty][nextx] == 0 && arr[nexty][nextx] == s) {
					visited_n[nexty][nextx] = 1;
					q.push(make_pair(nexty, nextx));
				}
			}
		}
	}
}
void bfs_rg(int sy, int sx, char s) {
	visited_rg[sy][sx] = 1;
	q.push(make_pair(sy, sx));
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nexty = nowy + dy[i];
			int nextx = nowx + dx[i];
			if (nextx >= 0 && nextx < N && nexty >= 0 && nexty < N) {
				if (visited_rg[nexty][nextx] == 0) {
					if (s == 'R' || s == 'G' ? arr[nexty][nextx] == 'R' || arr[nexty][nextx] == 'G' : arr[nexty][nextx] == 'B') {
						visited_rg[nexty][nextx] = 1;
						q.push(make_pair(nexty, nextx));
					}
				}
			}
		}
	}
}
int main(void) {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited_n[i][j] == 0) {
				if (arr[i][j] == 'R') {
					bfs_n(i, j, 'R');
					cnt_n++;
				}
				else if (arr[i][j] == 'B') {
					bfs_n(i, j, 'B');
					cnt_n++;
				}
				else {
					bfs_n(i, j, 'G');
					cnt_n++;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited_rg[i][j] == 0) {
				if (arr[i][j] == 'R') {
					bfs_rg(i, j, 'R');
					cnt_rg++;
				}
				else if (arr[i][j] == 'B') {
					bfs_rg(i, j, 'B');
					cnt_rg++;
				}
				else {
					bfs_rg(i, j, 'G');
					cnt_rg++;
				}
			}
		}
	}
	printf("%d %d", cnt_n, cnt_rg);

	return 0;
}
