#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int A, B, C;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	int product = A * B * C;
	char product_arr[100];

	sprintf(product_arr, "%d", product);                //char형 배열에 결과 저장

	for (int i = 0; i < 10; i++) {
		int temp = 0;
		for (int j = 0; product_arr[j] != 0; j++) { // 널값이 나올때까지 반복
			if (product_arr[j] == i + 48)           // char형과 int형 비교
				temp += 1;
		}
		printf("%d\n", temp);
	}
}