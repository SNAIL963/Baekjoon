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

int N, M;
int arr[55][55];
vector <pair <int, int>> chik;
vector <int> c; // 현재 조합
bool visited[15];
int minChicken = inf;
int thisChicken = 0;

void Com(int index) {
	if (c.size() == M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {
					int mindis = inf;
					for (int k = 0; k < c.size(); k++) {
						int thisDis = abs(chik[c[k]].first - i) + abs(chik[c[k]].second - j);
						mindis = min(mindis, thisDis);
					}
					thisChicken += mindis;
				}

			}
		}
		minChicken = min(thisChicken, minChicken);
		thisChicken = 0;

		return;
	}
	for (int i = index; i < chik.size(); i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		c.push_back(i);
		Com(i);
		c.pop_back();
		visited[i] = false;
	}
}

int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			scanf("%d", &x);
			if (x == 2)
				chik.push_back({ i,j });  // 치킨집 위치저장
			else if (x == 1) arr[i][j] = x;
		}
	}

	Com(0);
	printf("%d", minChicken);

	return 0;
}