#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 10100

using namespace std;

int k, n;
int arr[MAX];
int p[MAX];         // p
int pp[MAX];        // p'
int pNum, ppNum;    // p와 pp에 속한 색상의 종류의 개수
int ans = MAX;      // p'의 최소길이

void rainbow() {
	if (pp[arr[1]] == 0) ppNum++;
	pp[arr[1]]++;
	if (p[arr[1]] == 1)	pNum--;
	p[arr[1]]--;

	int left = 1;
	int right = 1;
	while (left <= right) {	
		// right 증가연산
		if (ppNum < k && right != n) {
			right++;

			if (pp[arr[right]] == 0)	ppNum++;
			pp[arr[right]]++;
			if (p[arr[right]] == 1)	pNum--;
			p[arr[right]]--;
		}
		// double rainbow 만들어진경우
		else if (ppNum == k && pNum == ppNum) {
			ans = min(ans, right - left + 1);

			if (p[arr[left]] == 0)	pNum++;
			p[arr[left]]++;
			if (pp[arr[left]] == 1)	ppNum--;
			pp[arr[left]]--;
			left++;
		}
		// left 증가연산
		else {
			if (p[arr[left]] == 0)	pNum++;
			p[arr[left]]++;
			if (pp[arr[left]] == 1)	ppNum--;
			pp[arr[left]]--;

			left++;
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		arr[i] = x;
		if (p[x] == 0) {
			pNum++;
		}
		p[x]++;
	}

	rainbow();

	if (ans == MAX)	printf("0");
	else printf("%d", ans);

	return 0;
}