#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {	
	
	while (true) {
		char num[6];
		scanf("%s", num);

		int j,size = 0;
		for (int i = 0; num[i] != 0; i++)
			size++;

		if (num[0] == '0')
			break;
		else{
			for (j = 0; j < size / 2; j++) {
				if (num[j] == num[size - j - 1])
					continue;
				else break;
			}
			if (j == size / 2)  printf("yes\n");
			else printf("no\n");
		}
	}
}