#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool mysort(int a, int b) {
	return a > b;
}

int main(void) {
	int size;
	scanf("%d", &size);

	vector <int> A;
	vector <int> B;

	for (int i = 0; i < size; i++) {
		int x;
		scanf("%d", &x);
		A.push_back(x);
	}
	for (int i = 0; i < size; i++) {
		int y;
		scanf("%d", &y);
		B.push_back(y);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(),mysort);

	int ans=0;

	for (int i = 0; i < size; i++) {
		ans += A[i]*B[i];
	}
	printf("%d", ans);
}