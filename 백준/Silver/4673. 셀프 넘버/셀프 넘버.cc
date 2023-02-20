#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int arr[10050] = { 0 };

	for (int i = 1; i <= 10000; i++) {
		int temp = i;
		int sum = i;
		while (temp != 0) {
			sum += temp % 10;
			temp = temp / 10;
		}
		arr[sum] = true;
	}
	for (int i = 1; i <= 10000; i++) {
		if (!arr[i]) {
			printf("%d\n", i);
		}
	}
}