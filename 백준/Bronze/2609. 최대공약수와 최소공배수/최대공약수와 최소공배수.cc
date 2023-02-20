#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int gcd(int a, int b) {
	if (a % b == 0) 
		return b;
	return gcd(b, a % b);
}
int main() {
	int num1;
	int num2;
	scanf("%d %d", &num1,&num2);

	printf("%d\n",gcd(num1,num2));
	printf("%d", (num1 * num2) / gcd(num1, num2));
}