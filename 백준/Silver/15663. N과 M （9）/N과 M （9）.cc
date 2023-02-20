#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int visited[10];
int ans[10];

void go(int a) {
	if (a == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	int prev_num = -1;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0 && prev_num != arr[i]) {
			visited[i] = 1;
			ans[a] = arr[i];
			prev_num = arr[i];
			go(a+1);
			visited[i] = 0;
		}
	}
}
int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	go(0);

	return 0;
}