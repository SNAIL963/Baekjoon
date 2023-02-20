#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#define max 100000

using namespace std;

long long a, b;
int answer = max;

void dfs(long long now, int depth) {
	if (now > b)
		return;
	else if (now == b) {
		answer = min(answer, depth);
		return;
	}

	dfs(now * 2, depth + 1);
	dfs(now * 10 + 1, depth + 1);
}
int main(void) {
	scanf("%lld %lld", &a, &b);

	dfs(a, 1);

	answer == max ? printf("-1") : printf("%d", answer);
	return 0;
}