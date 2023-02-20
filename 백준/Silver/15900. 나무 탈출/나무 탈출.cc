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
#define MAX 501000

using namespace std;

vector <vector <int>> edge(MAX);
int N;
int temp = 0;
int visited[MAX];
int answer = 0;

void tree(int now) {
	int size = edge[now].size();
	if (now != 1 && size == 1) {
		answer += temp;
		return;
	}
	visited[now] = 1;
	for (int i = 0; i < edge[now].size(); i++) {
		if (visited[edge[now][i]] == 0) {
			temp++;
			tree(edge[now][i]);
			temp--;
		}
	}
}
int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N-1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	tree(1);

	if(answer % 2 ==0)
		printf("No");
	else 
		printf("Yes");

	return 0;
}