#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int card;
	int num;
	int ans = 0;

	scanf("%d %d", &card, &num);

	vector <int> v;
	for (int i = 0; i < card; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}

	for (int i = 0; i < card - 2; i++) {
		for (int j = i + 1; j < card - 1; j++) {
			for (int k = j + 1; k < card; k++) {
				if (v[i] + v[j] + v[k] <= num && v[i] + v[j] + v[k] > ans)
					ans = v[i] + v[j] + v[k];
				else
					continue;
			}
		}
	}
	printf("%d", ans);

	return 0;
}
