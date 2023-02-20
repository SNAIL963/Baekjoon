#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int people;
	scanf("%d", &people);

	int time[1000];
	int sum = 0;

	for (int i = 0; i < people; i++)
		scanf("%d", &time[i]);

	sort(time, time + people);

	for (int i = 0; i < people; i++) {
		for (int j = 0; j < i + 1; j++)
			sum += time[j];
	}
	printf("%d", sum);
}