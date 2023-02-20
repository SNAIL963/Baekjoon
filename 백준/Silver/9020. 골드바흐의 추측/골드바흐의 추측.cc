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

int n,K;
bool sosu[10100];
int cnt = 0;


int main(void) {
	scanf("%d", &K);

	for (int i = 2; i < 10100; i++) {
		if (sosu[i] == true) continue;
		for (int j = i * 2; j < 10100; j = j + i) {
			if (sosu[j] == true) continue;
			sosu[j] = true;
		}
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &n);
		for (int j = 0; (n / 2) - j > 0; j++) {
			if (sosu[(n / 2) - j] == 0 && sosu[(n / 2) + j] == 0) {
				printf("%d %d\n", (n / 2) - j, (n / 2) + j);
				break;
			}
		}
	}

	return 0;
}