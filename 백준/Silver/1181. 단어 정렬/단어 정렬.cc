#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int size;
	scanf("%d", &size);
	vector <pair<int, string>> v;

	for (int i = 0; i < size; i++) {
		string str;
		cin >> str;
		v.push_back({ str.length(),str });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < size; i++) {
		if (i && v[i].second == v[i - 1].second) continue;
		cout << v[i].second << endl;
	}
}