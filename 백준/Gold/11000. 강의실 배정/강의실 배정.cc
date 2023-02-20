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

int N;
vector <pair <int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq2;

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());

	int i = 0;
	int cnt = 0;
	while (1) {	
		int start = v[i].first;
		int end = v[i].second;
		pq2.push(end);

		if (pq2.top() <= start) {  // 앞에서 사용한 강의실을 사용하는 경우
			pq2.pop();
		}
		else if (pq2.top() > start) {   // 새로운 강의실을 사용하는 경우
			cnt++;
		}
		if (i == v.size() - 1) break;
		else i++;
	}

	printf("%d", cnt);

	return 0;
}