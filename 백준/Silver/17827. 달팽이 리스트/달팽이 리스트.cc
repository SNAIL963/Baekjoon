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

int N, M, V, K;
int arr[200100];;

int main(void) {
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &K);
		if (K < N) printf("%d\n", arr[K+1]);
		else {
			printf("%d\n", arr[((K - V +1) % (N - V + 1)) + V]);
		}
	}

	return 0;
}
