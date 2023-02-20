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

int N;
vector <pair <char, char>> node;

void pre(char now) {
	if (now == '.') return;
	cout << now;
	pre(node[now - 'A'].first);
	pre(node[now - 'A'].second);
}
void in(char now) {
	if (now == '.') return;	
	in(node[now - 'A'].first);
	cout << now;
	in(node[now - 'A'].second);
}
void post(char now) {
	if (now == '.') return;	
	post(node[now - 'A'].first);
	post(node[now - 'A'].second);
	cout << now;
}
int main(void) {
	cin >> N;
	node.resize(N);

	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		node[a - 'A'].first = b;
		node[a - 'A'].second = c;
	}

	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	post('A');
	cout << '\n';

	return 0;
}