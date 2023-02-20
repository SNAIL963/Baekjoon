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
#include <map>
#include <set>
#define MAX 1050

using namespace std;

map <string, int> m;
int n;

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		m[s]++;
	}
	int max = 0;
	string title;
	for (auto i : m) {
		if (max < i.second) {
			max = i.second;
			title = i.first;
		}
	}
	cout << title;

	return 0;
}