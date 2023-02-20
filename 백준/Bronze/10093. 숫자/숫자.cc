#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	long long A, B;
	scanf("%lld %lld", &A, &B);

	if (A != B) {
		if (A > B) {
			long long temp;
			temp = A;
			A = B;
			B = temp;
		}
		printf("%lld\n", B - A - 1);
		for (long long i = A + 1; i < B; i++) {
			printf("%lld ", i);
		}
	}
	else
		printf("0");
}