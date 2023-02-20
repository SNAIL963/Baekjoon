#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visited[9] = {0};
int index = 1;
int N;
int M;
vector <int> ans;
// N개의 숫자중에서 M개를 골라서 순열을 만들어라

int per() {
	if (ans.size() == M) {
		int x = ans.size();
		for (int i = 0; i < x; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return 0;
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				ans.push_back(i);
				visited[i] = 1;
				per();
				ans.pop_back();
				visited[i] = 0;
			}
		}
	}
	return 0;
}
int main(void) {
	scanf("%d %d", &N, &M);

	per();
}