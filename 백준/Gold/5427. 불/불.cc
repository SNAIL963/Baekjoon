#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#define max 999999;

using namespace std;

int w, h, K;
string arr[1100];             // 값 입력
int visited_Fire[1100][1100];
int visited_Me[1100][1100];    // 방문 확인
queue <pair <int, int>> q;    // 좌표 표시
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int answer;

void bfs_M(int srty, int srtx) {
	visited_Me[srty][srtx] = 1;
	q.push(make_pair(srty, srtx));
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nexty = nowy + dy[i];
			int nextx = nowx + dx[i];
			if (nextx >= 0 && nextx < w && nexty >= 0 && nexty < h && arr[nexty][nextx] == '.'
				&& visited_Me[nexty][nextx] == 0) {
				if (visited_Fire[nexty][nextx] > visited_Me[nexty][nextx]) {
					q.push(make_pair(nexty, nextx));
					visited_Me[nexty][nextx] = visited_Me[nowy][nowx] + 1;
				}
			}
		}
	}
}
void bfs_F(int srty, int srtx) {      // 불 영역+나갈수 있나 확인 
	visited_Fire[srty][srtx] = 1;
	q.push(make_pair(srty, srtx));
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nexty = nowy + dy[i];
			int nextx = nowx + dx[i];
			if (nextx >= 0 && nextx < w && nexty >= 0 && nexty < h && arr[nexty][nextx] == '.') {
				if (visited_Fire[nexty][nextx] > visited_Fire[nowy][nowx] + 1) {
					q.push(make_pair(nexty, nextx));
					visited_Fire[nexty][nextx] = visited_Fire[nowy][nowx] + 1;
				}
			}
		}
	}
}
void ans() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && visited_Me[i][j] > 0
				&& visited_Me[i][j] < visited_Fire[i][j]) {
				answer = min(answer, visited_Me[i][j]);
			}
		}
	}
	if (answer == 999999)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", answer);
}
int main(void) {
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		answer = 999999;
		scanf("%d %d", &w, &h);

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visited_Fire[i][j] = max;
				visited_Me[i][j] = 0;
			}
		}
		for (int i = 0; i < h; i++) {
			cin >> arr[i];
		}
		int startx, starty;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == '*') {
					starty = i;
					startx = j;
					bfs_F(starty, startx);
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == '@') {
					starty = i;
					startx = j;
					bfs_M(starty, startx);
				}
			}
		}

		ans();
	}
	return 0;
}