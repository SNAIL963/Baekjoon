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
	deque <char> dq;
	int N, T;
	char arr[1010];

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%s", &arr[j]);
		}
		for (int k = 0; k < N; k++) {
			if (dq.empty()) {
				dq.push_back(arr[k]);
			}
			else if (dq.front() >= arr[k]) {
				dq.push_front(arr[k]);
			}
			else
				dq.push_back(arr[k]);
		}
		int x = dq.size();
		for (int i = 0; i < x; i++) {
			printf("%c", dq.front());
			dq.pop_front();
		}
		printf("\n");
		dq.clear();
	}

	return 0;
}