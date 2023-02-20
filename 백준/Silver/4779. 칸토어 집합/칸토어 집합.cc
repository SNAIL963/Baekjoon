#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <char> v;

void kant(int s, int size) {
	if (size == 1)
		return;
	fill(v.begin() + s + size / 3, v.begin() + s + size * 2 / 3, ' ');
	kant(s, size / 3);
	kant(s + size * 2 / 3, size / 3);
}
int main(void) {
	int num;
	while (scanf("%d", &num) != EOF) {
		for (int i = 0; i < pow(3, num); i++) {
			v.push_back('-');
		}
		kant(0, (int)pow(3, num));
		for (int i = 0; i < pow(3, num); i++) {
			printf("%c", v[i]);
		}
		printf("\n");
	}
}