#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[105] = { 0,1,1,1,2,2, };
int num, n;

long long P(int a) {
	for (int i = 6; i <= a; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	return arr[a];
}

int main(void) {
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &n);
		printf("%lld\n", P(n));
	}
}