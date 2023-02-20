#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int visited[9];
int arr[9];
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
				ans.push_back(arr[i]);
				go(i);
				visited[i] = 0;
				ans.pop_back();
			}
		}
	}
}
int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(&arr[1], &arr[1] + n);
	
	go(1);

	return 0;
}