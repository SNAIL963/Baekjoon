#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
vector <int> ans;

void go() {
	if (ans.size() == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
				ans.push_back(arr[i]);
				go();
				ans.pop_back();
		}
	}
}
int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(&arr[1], &arr[1] + n);
	
	go();

	return 0;
}