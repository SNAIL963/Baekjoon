#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> v;  // 만든 수
int arr[3];      // 입력받은 수 저장
int N, K;
int ans = 0;

void big() {
	int num = 0;  // 입력받은수
	int a = 1;    // 자리수
	int x = v.size();
	for (int i = 0; i < x; i++) {
		num += v[i] * a;
		a = a * 10;
	}
	if (num > N) return;
	else if (num > ans) {
		ans = num;
	}
	for (int j = 0; j < K; j++) {
		v.push_back(arr[j]);
		big();
		v.pop_back();
	}
}
int main(void) {
	scanf("%d %d", &N, &K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &arr[i]);
	}
	sort(&arr[0], &arr[K - 1]);
	big();
	printf("%d", ans);
	return 0;
}