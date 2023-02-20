#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void print_n(int size) {
	if (size == 1)
		printf("1");
	else {
		printf("%d\n", size);
		print_n(size - 1);
	}
}
int main() {
	int size;
	scanf("%d", &size);
	print_n(size);
}