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

using namespace std;

int n;
bool sosu[300000];
int cnt = 0;


int main(void) {
	scanf("%d", &n);

	for (int i = 2; i < 300000; i++) {
		if (sosu[i] == true) continue;
		for (int j = i * 2; j < 300000; j = j + i) {
			if (sosu[j] == true) continue;
			sosu[j] = true;
		}
	}
	while (!n == 0) {
		for (int i = n + 1; i <= 2 * n; i++) {
			if (sosu[i] == false) cnt++;
		}
		printf("%d\n", cnt);
		cnt = 0;
		scanf("%d", &n);
	}
}