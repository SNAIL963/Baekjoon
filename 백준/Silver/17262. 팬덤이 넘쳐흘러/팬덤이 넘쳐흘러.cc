#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int fans;
	scanf("%d", &fans);

	vector <pair<int, int>> v;

	for (int i = 0; i < fans; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back(pair<int, int>(x, y));
	}
	int max_first = v[0].first; 
	int min_second = v[0].second;

	for (int i = 0; i < fans; i++) {
		if (max_first < v[i].first)
			max_first = v[i].first;
		if (min_second > v[i].second)
			min_second = v[i].second;
	}

	if (v.size() == 1)
		printf("0");
	else if (max_first < min_second) {
		printf("0");
	}
	else printf("%d", max_first - min_second);
}