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

int N, M;
string arr[110];       // 값 입력
int visited[110][110]; // 방문 확인
queue <pair <int, int>> q;  // 좌표 표시
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int danji = 0;
vector <int> houseV;

void bfs(int a, int b) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0 && arr[i][j] == '1') {
				visited[i][j] = 1;
				q.push(make_pair(i, j));
				int house = 1;
				danji++;
				while (!q.empty()) {
					int nowx = q.front().first;
					int nowy = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nextx = nowx + dx[i];
						int nexty = nowy + dy[i];
						if (nextx >= 0 && nextx < N && nexty >= 0 && nexty < N && arr[nextx][nexty] == '1'
							&& visited[nextx][nexty] == 0) {
							q.push(make_pair(nextx, nexty));
							house++;
							visited[nextx][nexty] = 1;
						}
					}
				}
				houseV.push_back(house);
			}
		}
	}
}
int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	bfs(0, 0);
	sort(houseV.begin(), houseV.end());

	printf("%d\n", danji);
	int s = houseV.size();
	for (int i = 0; i < s; i++) {
		printf("%d\n", houseV[i]);
	}

	return 0;
}