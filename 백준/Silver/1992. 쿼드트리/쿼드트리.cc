#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <char> ans;
int arr[70][70];

void div(int x, int y, int size) {    // x, y가 시작좌표
	int first = arr[x][y];

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (first != arr[i][j]) {
				ans.push_back('(');
				div(x, y, size / 2);
				div(x, y + (size / 2), size / 2);
				div(x + (size / 2), y, size / 2);
				div(x + (size / 2), y + (size / 2), size / 2);
				ans.push_back(')');
				return;
			}
		}
	}

	if (first == 1)
		ans.push_back('1');
	else
		ans.push_back('0');
}

int main(void) {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	div(0, 0, num);

	int size = ans.size();
	for (int i = 0; i < size; i++) {
		printf("%c", ans[i]);
	}

	return 0;
}