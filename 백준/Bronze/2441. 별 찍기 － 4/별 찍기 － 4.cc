#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int line;
	scanf("%d", &line);

	for (int i = 0; i < line; i++) {
		for (int k = 0; k < i; k++) {
			printf(" ");
		}
		for (int j = i; j < line; j++) {   // 띄어쓰기는 줄마다 감소하므로 j를 i로
			printf("*");
		}
		printf("\n");
	}
}