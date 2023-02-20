#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_nine(int* arr) {
	int count = 0;
	int num = *arr;

	while (num != 0) {
		if ((num) % 10 == 9)
			count++;
		num = num / 10;
	}
	return count;
}

int main(void) {
	int arr[500][500];
	int nine = 0;
	int sero = 0;
	int garo = 0;
	int max = 0;

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			nine += count_nine(&arr[i][j]);
	}

	for (int i = 0; i < n; i++) {
		int max_garo = 0;
		for (int j = 0; j < m; j++)
			max_garo += count_nine(&arr[i][j]);
		if (max_garo > garo)
			garo = max_garo;
	}
	for (int j = 0; j < m; j++) {
		int max_sero = 0;
		for (int i = 0; i < n; i++)
			max_sero += count_nine(&arr[i][j]);
		if (max_sero > sero)
			sero = max_sero;
	}
	if (garo > sero)
		max = garo;
	else max = sero;

	printf("%d", nine - max);
}