#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);

	vector <int> vector1;

	for (int i = 0; i < num; i++) {
		int a;
		scanf("%d", &a);
		vector1.push_back(a);
	}
	sort(vector1.begin(), vector1.end());
	
	for (int i = 0; i < num; i++) {
		printf("%d\n", vector1[i]);
	}
}