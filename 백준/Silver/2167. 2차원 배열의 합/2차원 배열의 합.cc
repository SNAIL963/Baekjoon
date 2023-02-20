#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int arr[300][300];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	}
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int I, J, X, Y;
		int sum = 0;
		scanf("%d %d %d %d",&I, &J, &X, &Y);
		
		for (int j = I-1; j < X; j++) {
			for (int k = J-1; k < Y; k++) {
				sum += arr[j][k];
			}
		}
		printf("%d\n", sum);
	}
}