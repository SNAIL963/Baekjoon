#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int num;
	scanf("%d", &num);
	int answer;
	int yes = 0;
	int no = 0;

	for (int i = 0; i < num; i++) {
		scanf("%d", &answer);
		if (answer == 1)
			yes += 1;
		else if(answer == 0)
			no += 1;
	}
	if (yes > no)
		printf("Junhee is cute!");
	else
		printf("Junhee is not cute!");
}