#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int color[300100];
int answer;

int go(int left, int right) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		int temp = 0;
		for (int i = 1; i <= m; i++) {
			temp += color[i] / middle;
			if (color[i] % middle)       // 나머지가 존재한다면
				temp++;                  // 하나 더 증가
		}
		if (n < temp) {                  // 불가능
			left = middle + 1;
		}
		else {                           // 가능
			right = middle - 1;
			if (middle < answer) {
				answer = middle;
			}
		}
	}
	return answer;
}
int main(void) {
	scanf("%d %d", &n, &m);

	int maxValue = 1;

	for (int i = 1; i <= m; i++) {
		scanf("%d", &color[i]);
		maxValue = max(maxValue, color[i]);
	}
	answer = maxValue;

	printf("%d", go(1, maxValue));

	return 0;
}