#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <char> v;        // 문자의 종류
vector <char> ans;      // 출력
int visited[15] = { 0 };
int count_ga = 0;       // 모음개수
int L, C;

int check(vector <char>& ptr) {     // 모음 자음 조건
	int x = ptr.size();
	count_ga = 0;
	for (int i = 0; i < x; i++) {
		if (ptr[i] == 'a' || ptr[i] == 'e' || ptr[i] == 'i' || ptr[i] == 'o' || ptr[i] == 'u')
			count_ga++;
	}

	if (count_ga == 0 || L - count_ga < 2)   // 모음이 없거나, 자음의 수가 2 이하
		return 0;
	else
		return 1;
}
void go(int depth) {
	if (ans.size() == L && check(ans)) {
		int size = ans.size();
		for (int i = 0; i < size; i++) {
			printf("%c", ans[i]);
		}
		printf("\n");
		return;
	}
	else
		for (int j = depth; j < C; j++) {
			if (visited[j] == 0) {
				ans.push_back(v[j]);
				visited[j] = 1;
				go(j + 1);
				ans.pop_back();
				visited[j] = 0;
			}
			else continue;
		}
}

int main(void) {
	scanf("%d %d", &L, &C);

	for (int i = 0; i < C; i++) {
		char a;
		scanf(" %c", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	go(0);

	return 0;
}