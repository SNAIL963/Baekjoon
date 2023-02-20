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

int main(void) {
	queue <int> q;
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		q.push(i+1);
	}

	while (!(q.size() == 1)) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	printf("%d", q.front());

	return 0;
}