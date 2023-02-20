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

priority_queue <int> pq;
int n;

int main(void){
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (pq.size() == 0) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", pq.top());
			pq.pop();
		}
		else {
			for (int j = 0; j < x; j++) {
				int y;
				scanf("%d", &y);
				pq.push(y);
			}
		}
	}

	return 0;
}