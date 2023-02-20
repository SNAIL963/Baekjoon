#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int check_two_squred(int num) {
	if (num == 1)
		return 1;
	else if (num % 2 == 0 && num !=0)
		return check_two_squred(num / 2);
	else
		return 0;
}
int main() {
	int num;
	scanf("%d", &num);
	printf("%d", check_two_squred(num));
	return 0;
}