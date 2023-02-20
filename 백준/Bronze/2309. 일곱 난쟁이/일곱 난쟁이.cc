#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int over = 0;
	int not1 = 0;
	int not2 = 0;
	vector <int> v1;

	for (int i = 0; i < 9; i++) {
		int a;
		scanf("%d", &a);
		v1.push_back(a);
	}
	sort(v1.begin(), v1.end());
	
	for (int i = 0; i < 9; i++)
		over += v1[i];
	over -= 100;

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++)
			if (v1[i] + v1[j] == over) {
				not1 = i;
				not2 = j;
			}
	}

	v1.erase(v1.begin() + not1);
	v1.erase(v1.begin() + (not2-1));

	for (int i = 0; i < 7; i++) {
		printf("%d\n", v1[i]);
	}
}