#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int num;
	scanf("%d", &num);

	vector <int> v;

	for (int i = 0; i < num; i++) {
		v.push_back(i+1);
	}
	
	do {
		for (int j = 0; j < num; j++) {
			printf("%d ", v[j]);
		}
		
		printf("\n");

	} while (next_permutation(v.begin(), v.end()));

	return 0;
}