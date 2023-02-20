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
#include <map>
#include <set>
#define MAX 1050

using namespace std;

set <pair <int, int>> s;
int n;
int ga, se;
long long cnt;

int main(void) {
	cin >> n;
	cin >> ga >> se;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x,&y);
		s.insert({ x,y });
	}

	for (auto i : s) {
		if (s.count({ i.first + ga,i.second }) && s.count({ i.first,i.second+se })
			&& s.count({ i.first + ga,i.second+se })) {
			cnt++;
		}
	}

	printf("%lld", cnt);

	return 0;
}