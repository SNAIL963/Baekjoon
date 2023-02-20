#include <stdio.h>

int main() {
	int num,count=0;
	scanf("%d", &num);
	char tmp;

	for (int i = 0; i < num; i++) {
		char str[101] = { 0 };
		scanf("%s", &str);
		for (int n = 0; n < 101; n++) {
			tmp = str[n];
			for (int k = n + 1; k < 101; k++) {
				if (str[k] == tmp)
					continue;
				else
					for (int l = k + 1; l < 101; l++)
						if (str[l] == tmp)
							goto EXIT;
						else if (str[l] == 0)
							break;
			}
		}
		count++;
		EXIT:;
	}
	printf("%d", count);
}