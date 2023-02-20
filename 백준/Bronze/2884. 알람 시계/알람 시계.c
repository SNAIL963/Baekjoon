#include <stdio.h>

int main() {

	// 9번 알람시계
	int hour;
	int minute;
	scanf("%d %d", &hour, &minute);

	if (minute < 45) {
		minute = minute + 15;
		if (hour == 0) {
			hour = 23;
		}
		else hour = hour - 1;
	}
	else if (45 <= minute <= 59) {
		minute = minute - 45;		 
	}

	printf("%d %d", hour, minute);
	return 0;
}