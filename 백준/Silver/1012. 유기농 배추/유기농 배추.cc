#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#define MAX 100100

using namespace std;

int T;
int M, N, K;
int field[51][51];
int visited[51][51];
int answer;
int col[4] = { 1,-1,0,0 };
int row[4] = { 0,0,1,-1 };

void dfs(int y, int x) {
	if (visited[y][x]) {
		return;
	}

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nextY = y + col[i];
		int nextX = x + row[i];
		if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N && !visited[nextY][nextX] && field[nextY][nextX]) {
			dfs(nextY, nextX);
		}
	}
}

int main(void) {
	cin >> T;

	for (int a = 0; a < T; a++) {
		cin >> M >> N >> K;
		memset(field, 0, sizeof(field));
		memset(visited, 0, sizeof(visited));
		answer = 0;

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[j][i] == 0 && field[j][i] == 1) {
					answer++;
					dfs(j, i);
				}
			}
		}
		printf("%d\n", answer);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				field[i][j] = 0;
			}
			
		}
		
	}
	return 0;
}