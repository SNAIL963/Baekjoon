#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector <int> v;
	int N, K;
	int arr[1050] = { 1,1,0, };

	scanf("%d %d", &N, &K);

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (arr[j] == 0) {
				arr[j] = 1;
				v.push_back(j);
			}
			else if (arr[i] == 1) continue;
		}
	}
	printf("%d", v[K-1]);
}