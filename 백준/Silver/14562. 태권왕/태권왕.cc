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

using namespace std;

int S, T, K;
bool sosu[10100];
int ans = 100;

void bfs(int s, int t, int num) {
	if (s > t) return;
	else if (s == t) {
		ans = min(ans, num);
	}

	bfs(s * 2, t + 3, num+1);
	bfs(s + 1, t, num+1);
}
int main(void) {
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		ans = 100;
		scanf("%d %d", &S, &T);
		bfs(S, T, 0);
		printf("%d\n", ans);
	}

	return 0;
}