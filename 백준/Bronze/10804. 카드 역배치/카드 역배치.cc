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
#define inf 100000000001

using namespace std;

int main(void) {
	vector<int>arr(21);
	for (int i = 1; i <= 20; i++) arr[i] = i;
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;

		reverse(arr.begin() + a, arr.begin() + b + 1);
	}

	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}