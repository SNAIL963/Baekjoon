#include <stdio.h>

int main() {
	char str[1000001] = { 0 };
	scanf("%[^\n]s", str);
	int n = 0;
	int word_count = 0;

	while (!(str[n] == 0 && str[n + 1] == 0)) {
		if (n == 0 && str[n] != 32)
			word_count += 1;
		if (str[n] == 32) {
			if (str[n + 1] == 0) 
				break;
			else {
				word_count += 1;
			}
		}
		n += 1;
	}
	printf("%d\n", word_count);
	return 0;
}