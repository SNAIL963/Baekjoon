#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector <int> ans;

void go(int a) {   // a는 가장 마지막에 집어넣은 숫자
	if (ans.size() == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (int i = a; i <= n; i++) {
				ans.push_back(i);
				go(i);
				ans.pop_back();
		}
	}
}
int main(void) {
	scanf("%d %d", &n, &m);

	go(1);

	return 0;
}