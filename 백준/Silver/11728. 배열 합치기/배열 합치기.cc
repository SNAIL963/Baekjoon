#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector <int> v1;

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v1.push_back(a);
	}
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		v1.push_back(a);
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < n+m; i++) {
		printf("%d ", v1[i]);
	}
}