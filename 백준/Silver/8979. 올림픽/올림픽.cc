#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	int M_index;
	int ans = 1;

	int medal[1000][4];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &medal[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		if (medal[i][0] == M)
			M_index = i;
	}

	for (int i = 0; i < N; i++) {
		if (M_index != i) {
			if (medal[i][1] > medal[M_index][1]) {
				ans++;
			}
			else if (medal[i][1] = medal[M_index][1]) {
				if (medal[i][2] > medal[M_index][1])
					ans++;
				else if (medal[i][2] = medal[M_index][2]) {
					if (medal[i][3] > medal[M_index][3]) {
						ans++;
					}
				}
			}
			else continue;
		}
	}
	printf("%d", ans);
}