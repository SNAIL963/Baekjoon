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
	int N;
	scanf("%d", &N);

	queue <int> q;
	stack <int> s;

	int last = 0;

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		q.push(x);
	}

	while(!q.empty()){
		if (last + 1 == q.front()) {
			q.pop();
			last++;
		}
		else 
			if (!s.empty() && s.top() == last + 1) {
				s.pop();
				last++;
			}
			else {
				s.push(q.front());
				q.pop();
			}
	}

	int x = s.size();
	for (int j = 0; j < x; j++) {
		if (last + 1 != s.top())
			break;
		else {
			s.pop();
			last++;
		}
	}

	if (s.empty())
		printf("Nice");
	else
		printf("Sad");

	return 0;
}