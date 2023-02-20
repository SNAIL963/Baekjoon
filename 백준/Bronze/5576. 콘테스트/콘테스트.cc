#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector <int> w;
	vector <int> k;

	for (int i = 0; i < 10; i++) {
		int a;
		scanf("%d", &a);
		w.push_back(a);
	}
	for (int i = 0; i < 10; i++) {
		int b;
		scanf("%d", &b);
		k.push_back(b);
	}
	sort(w.begin(), w.end());
	sort(k.begin(), k.end());

	int w_score = w[7] + w[8] + w[9];
	int k_score = k[7] + k[8] + k[9];

	printf("%d %d", w_score, k_score);
}