#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int size;
	scanf("%d", &size);
	long long sum = 0;
	int ans = 0;
	
	for (int i = 0; i < size; i++) {
		int a;
		scanf("%d", &a);
		sum += a;
	}
	ans = sum - ((long long) size * (size - 1) / 2);
	printf("%d", ans);

}