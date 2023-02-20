#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, C;
int loc[200200];   // 집의 좌표
int Max;           // 집 사이의 거리의 최댓값
int ans = 0;

int router() {
	int left = 0;
	int right = Max;

	while (left <= right) {
		int middle = (left + right) / 2;  // middle : 가장 인접한 공유기 사이 거리
		int temp = loc[0];
		int count = 1;

		for (int i = 0; i < N; i++) {
			if (loc[i] - temp >= middle) {
				temp = loc[i];
				count++;
			}
		}
		if (count < C) {
			right = middle - 1;
			continue;
		}
		left = middle + 1;
		ans = max(ans, middle);
	}
	return ans;
}
int main() {
	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++) {
		scanf("%d", &loc[i]);
	}
	sort(loc, loc + N);
	
	Max = loc[N - 1] - loc[0];

	printf("%d", router());

	return 0;
}