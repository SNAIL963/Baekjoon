#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

long long gcd(long long a, long long b) {
	if (a % b == 0) 
		return b;
	return gcd(b, a % b);
}
int main() {
	long long num1;
	long long num2;
	scanf("%lld %lld", &num1,&num2);

	printf("%lld", (num1 * num2) / gcd(num1, num2));
    return 0;
}