#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool mysort(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) 
		return a.second < b.second;
	return a.first < b.first;
}

int main(void) {
	int num;
	scanf("%d", &num);
	vector <pair<int, int>> point;

	for (int i = 0; i < num; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		point.push_back(pair<int, int>(x, y));
	}
	sort(point.begin(), point.end(), mysort);

	for (int i = 0; i < num; i++) {
		printf("%d %d\n", point[i].first, point[i].second);
	}
}