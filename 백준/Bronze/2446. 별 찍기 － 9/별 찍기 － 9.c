#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < 2 * num - 1; i++) {
		if (i <= num - 1) {
			for (int k = 0;k<i ; k++) {
				printf(" ");
			}
			for (int j = 0; j < 2 * num - (i * 2 + 1); j++) {
				printf("*");
			}
			printf("\n");
		}
		else {
			for (int k = i; k < 2 * num - 2; k++) {
				printf(" ");
			}
			for (int j = 0; j < -2 * num + ((i+1) * 2 + 1); j++) {
				printf("*");
			}
			if(i!=2*num-2)
				printf("\n");
		}
	}
	return 0;
}