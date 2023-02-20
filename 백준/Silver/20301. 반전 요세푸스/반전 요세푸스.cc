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
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);
	deque <int> q;
	vector <int> order;
	bool rev = false;

	for (int i = 0; i < N; i++) {
		q.push_back(i + 1);
	}

	int k = 1;
	while (q.size() != 0) {
		if (k != K && !rev) {
			q.push_back(q.front());
			q.pop_front();
			k++;
		}
		else if (k != K && rev) {    // 역순
			q.push_front(q.back());
			q.pop_back();
			k++;
		}
		else if (k == K && !rev) {
			order.push_back(q.front());
			if (order.size() % M == 0) {
				if (rev)  rev = false;
				else  rev = true;
			}
			q.pop_front();
			k = 1;
		}
		else if (k == K && rev) {
			order.push_back(q.back());
			if (order.size() % M == 0) {
				if (rev)  rev = false;
				else  rev = true;
			}
			q.pop_back();
			k = 1;
		}

	}

	int end = order.size();
	for (int i = 0; i < end; i++) {
		printf("%d\n", order[i]);
	}

	return 0;
}