#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int num;
	scanf("%d", &num);
	vector <pair<pair<int, int>, int>> v;

	for (int i = 0; i < num; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back({ { x,y },1 });
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (v[i].first.first < v[j].first.first && v[i].first.second < v[j].first.second)
				v[i].second++;
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%d ", v[i].second);
	}
}