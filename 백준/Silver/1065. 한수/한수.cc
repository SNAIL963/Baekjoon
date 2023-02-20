#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num; 
	scanf("%d", &num);
	int il, sib, baek;
	int ans=99;

	for (int i = 100; i <= num; i++) {
		if (num >= 100) {
			il = i % 10;
			sib = (i / 10) % 10;
			baek = i / 100;

			if ((il <= sib && sib <= baek) && baek - sib == sib - il) {
				ans++;
				continue;
			}
			else if ((il >= sib && sib >= baek) && il - sib == sib - baek) {
				ans++;
				continue;
			}
		}
		else break;
	}
	if (num < 100)
		printf("%d", num);
	else
		printf("%d", ans);
}