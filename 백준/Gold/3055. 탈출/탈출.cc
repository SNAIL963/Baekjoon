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

int w, h, K;
string arr[55];             // 값 입력
int visited_Water[55][55];
int visited_Me[55][55];    // 방문 확인
queue <pair <int, int>> q;    // 좌표 표시
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int answer;

void bfs_W(int srty, int srtx) {      // 물 영역+나갈수 있나 확인 
	visited_Water[srty][srtx] = 1;
	q.push(make_pair(srty, srtx));
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nexty = nowy + dy[i];
			int nextx = nowx + dx[i];
			if (nextx >= 0 && nextx < w && nexty >= 0 && nexty < h && arr[nexty][nextx] == '.') {
				if (visited_Water[nexty][nextx] > visited_Water[nowy][nowx] + 1) {
					q.push(make_pair(nexty, nextx));
					visited_Water[nexty][nextx] = visited_Water[nowy][nowx] + 1;
				}
			}
		}
	}
}
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
			if (nextx >= 0 && nextx < w && nexty >= 0 && nexty < h &&
				(arr[nexty][nextx] == '.' || arr[nexty][nextx] == 'D')
				&& visited_Me[nexty][nextx] == 0) {
				if (visited_Water[nexty][nextx] > visited_Me[nowy][nowx] +1) {
					q.push(make_pair(nexty, nextx));
					visited_Me[nexty][nextx] = visited_Me[nowy][nowx] + 1;
				}
			}
		}
	}
}
int main(void) {
	answer = inf;
	scanf("%d %d", &h, &w);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			visited_Water[i][j] = inf;
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
				bfs_W(starty, startx);
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'S') {
				starty = i;
				startx = j;
				bfs_M(starty, startx);
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'D'){
				if (visited_Me[i][j] > 0 && visited_Me[i][j] < visited_Water[i][j]) {
					answer = min(answer, visited_Me[i][j]);
				}
			}
		}
	}
	if (answer == inf)
		printf("KAKTUS\n");
	else
		printf("%d\n", answer - 1);

	return 0;
}