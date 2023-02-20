#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int visited[9];
vector <int> ans;

void go(int a) {
	if (ans.size() == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (int i = a; i <= n; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				ans.push_back(i);
				go(i);
				visited[i] = 0;
				ans.pop_back();
			}
		}
	}
}
int main(void) {
	scanf("%d %d", &n, &m);

	go(1);

	return 0;
}