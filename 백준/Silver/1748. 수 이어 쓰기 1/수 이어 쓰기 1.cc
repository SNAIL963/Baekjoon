#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int add = 1;
	int number;
	scanf("%d", &number);

	int x=10;
	int sum=0;

	for (int i = 1; i <= number; i++) {
		sum += add;
		if (i+1==x) {
			x *= 10;
			add++;
		}
	}
	printf("%d", sum);
}