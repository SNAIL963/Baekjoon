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
#define MAX 10100

using namespace std;

// 인오더 순으로 정렬
// 정렬한 순서대로 i = 0 부터 이차원 배열에 넣음

vector <pair<int, int>> edge;
vector <int> node;
bool arr[MAX][MAX];
vector <int> width;          // column 번호
int N;
int temp = 0;
int depth = -1;
int answerCol = 0;
int answer = 0;

void inorder(int now) {
	if (now == -1) return;
	depth++;
	inorder(edge[now].first);
	arr[depth][temp] = 1;
	temp++;
	inorder(edge[now].second);
	depth--;
}
void search_width(int index, int le, int re) {
	while (true) {
		if (arr[index][le] == 1) break;
		le++;
		if (le > N) return;
	}
	while (true) {
		if (arr[index][re] == 1) break;
		re--;
	}
	width[index] = re - le + 1;
}
int main(void) {
	scanf("%d", &N);
	
	edge.resize(N + 1);
	node.resize(N + 1);
	width.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		node[x]++;

		if (y != -1) node[y]++;
		edge[x].first = y;
		if (z != -1) node[z]++;
		edge[x].second = z;
	}

	int root;
	for (int i = 1; i <= N; i++) {
		if (node[i] == 1)
			root = i;
	}

	inorder(root);

	for (int i = 0; i < N; i++) {
		search_width(i, 0, N);
	}
	for (int i = 0; i < N; i++) {
		if (answer < width[i]) {
			answer = width[i];
			answerCol = i;
		}
	}
	printf("%d %d", answerCol + 1, answer);

	return 0;
}