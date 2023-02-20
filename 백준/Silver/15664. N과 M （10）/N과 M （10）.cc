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

void go(int index, int a) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	int prev_num = -1;
	for (int i = a; i < n; i++) {
		if (visited[i] == 0 && prev_num != arr[i]) {
			visited[i] = 1;
			ans[index] = arr[i];
			prev_num = arr[i];
			go(index+1, i);
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

	go(0, 0);

	return 0;
}