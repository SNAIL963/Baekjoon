#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[100100];
int check[100100];

int go(int i) {    // 찾으려는 값 i
	int left = 0;
	int right = n - 1;
	int middle = (left + right) / 2;

	while (left <= right) {
		if (arr[middle] == i)
			return 1;
		else if (arr[middle] > i) {
			right = middle - 1;
		}
		else
			left = middle + 1;

		middle = (left + right) / 2;
	}
	return 0;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &check[i]);
	}

	for (int i = 0; i < m; i++) {
		printf("%d\n", go(check[i]));
	}

	return 0;
}