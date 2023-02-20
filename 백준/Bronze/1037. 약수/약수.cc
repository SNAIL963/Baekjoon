#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num;
	scanf("%d", &num);

	vector <int> v;

	for (int i = 0; i < num; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	printf("%d", v[0]*v[num-1]);
}