#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#define inf 1000000000

using namespace std;

int n,m;
int arr[105][105];
vector <pair <int, int>> adj[101000];

void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}
int main(void) {
	scanf("%d", &n);
	scanf("%d", &m);

	memset(arr, inf, sizeof(arr));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = inf;
		}	
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[a-1][b-1] = min(arr[a-1][b-1], c);
	}
	floyd();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == inf) printf("0 ");
			else printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}