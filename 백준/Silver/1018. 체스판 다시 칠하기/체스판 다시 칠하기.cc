#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	char ch[50][50] = {};

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", ch[i]);
	}

	int ans = 64;

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int B = 0;  // 시작지점이 검은색
			int W = 0;  // 시작지점이 흰색

			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if ((k + l) % 2 == 0) {        // 시작지점 색
						if (ch[k][l] == 'W')       // 검정인 경우
							B++;
						else if (ch[k][l] == 'B')  // 흰색인 경우
							W++;
					}
					else {
						if (ch[k][l] == 'B')
							B++;
						else if (ch[k][l] == 'W')
							W++;
					}
				}
			}
			if (ans > min(B, W))
				ans = min(B, W);
		}
	}
	printf("%d", ans);
}