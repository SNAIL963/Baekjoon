#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int over = 0;
	int not1 = 0;
	int not2 = 0;
	vector <int> v;

	for (int i = 0; i < 9; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < 9; i++)
		over += v[i];
	over -= 100;

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++)
			if (v[i] + v[j] == over) {
				not1 = i;
				not2 = j;
			}
	}
	v.erase(v.begin() + not1);
	v.erase(v.begin() + (not2 - 1));
	for (int i = 0; i < 7; i++) 
		printf("%d\n", v[i]);
}