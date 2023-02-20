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
#define MAX 1050

using namespace std;

priority_queue <pair <long long ,int>, vector <pair <long long, int>>, greater <pair <long long, int>>> pq;
int n, m;
long long arr[MAX];
long long ans;

int main(void){
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr[i] = x;
		pq.push({ x,i });
	}
	for (int i = 0; i < m; i++) {
		long long sum = 0;
		int id1, id2;
		sum += pq.top().first;
		id1 = pq.top().second;
		pq.pop();
		sum += pq.top().first;
		id2 = pq.top().second;
		pq.pop();

		arr[id1] = sum;
		pq.push({ sum,id1 });
		arr[id2] = sum;
		pq.push({ sum,id2 });
	}

	for (int i = 0; i < n; i++) {
		ans += arr[i];
	}

	printf("%lld", ans);
	return 0;
}