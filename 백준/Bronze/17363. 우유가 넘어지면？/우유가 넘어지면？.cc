#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	char a[8] = { '-',  '|',  '/',  '\\', '^',  '<', 'v', '>' };
	char b[8] = { '|',  '-',  '\\',  '/', '<',  'v', '>', '^'};

	char arr[101][101];
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = M-1; i > -1; i--) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 8; k++) {
				if (arr[j][i] == a[k]) {
					arr[j][i] = b[k];
					break;
				}
			}
			printf("%c", arr[j][i]);
		}
		printf("\n");
	}
}