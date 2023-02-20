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
	int N, K;
	scanf("%d %d", &N, &K);
	queue <int> q;
	vector <int> order;

	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}

	int k = 1;
	while (q.size() != 0) {
		if (k != K) {
			q.push(q.front());
			q.pop();
			k++;
		}
		else {
			order.push_back(q.front());
			q.pop();
			k = 1;
		}
	}

	printf("<"); int end = order.size()-1;
	for (int i = 0; i < end; i++) {
		printf("%d, ",order[i]);
	}
	printf("%d>", order[end]);

	return 0;
}