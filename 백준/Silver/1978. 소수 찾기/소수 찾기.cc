#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int ans = 0;
	int num;
	int arr[1050] = { 1,1,0, };

	scanf("%d", &num);

	vector <int> v;
	for (int i = 0; i < num; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}

	for (int i = 2; i <= 1000; i++) {
		if (arr[i] == 0)
			for (int j = i + i; j <= 1000; j += i)
				arr[j] = 1;
		else if (arr[i] == 1) continue;
	}

	for (int i = 0; i < num; i++) {
		if (arr[v[i]] != 1)
			ans++;
	}
	printf("%d", ans);
}