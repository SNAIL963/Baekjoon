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
#define MAX 1010

using namespace std;

int N, root;
vector <vector<int>> child;
int delNode;
int answer =0;

void leaf(int nowNode) {
	if (delNode == nowNode) return;
	int size = child[nowNode].size();
	switch (size) {
		case 0:
			answer++; return;
			break;
		case 1:
			if (child[nowNode][0] == delNode) {
				answer++;
				break;
			}
		default:
			for (int i = 0; i < size; i++) {
				leaf(child[nowNode][i]);
			}
			break;
	}
}
int main(void) {
	cin >> N;
	child.resize(N);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == -1) root = i;
		else child[num].push_back(i);
	}

	cin >> delNode;
	leaf(root);
	cout << answer;
	return 0;
}