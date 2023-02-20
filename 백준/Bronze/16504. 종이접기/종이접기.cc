#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int size = 0;
	scanf("%d", &size);
	long long sum = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int a = 0;
			scanf("%d", &a);
			sum += a;
		}
	}
	printf("%lld", sum);
}