#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k;
int num[12];
int visited[12] = { 0 };   // 1~8까지 방문여부 확인
vector <int> output;      // 출력용 벡터
int lotto = 6;

void per(int a) {
	if (output.size() == lotto) {
		int x = output.size();
		for (int i = 0; i < x; i++) {
			printf("%d ", output[i]);
		}
		printf("\n");
	}
	else {
		for (int i = a; i < k; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				output.push_back(num[i]);
				per(i + 1);
				visited[i] = 0;
				output.pop_back();
			}
			else continue;
		}
	}
}
int main(void) {
	do {

		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &num[i]);
		}

		per(0);
		printf("\n");
	} while (k != 0);
}