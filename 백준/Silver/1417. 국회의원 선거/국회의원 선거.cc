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
#define MAX 10100

using namespace std;

priority_queue <int> pq;
int N;
int cnt = 0;
int dasom;

void vote() {
	if (dasom > pq.top()) return;
	int p;
	p = pq.top() - 1;
	pq.pop();
	pq.push(p);
	dasom++;
	cnt++;
	vote();
}
int main(void) {
	scanf("%d", &N);
	scanf("%d", &dasom);
	for (int i = 0; i < N-1; i++) {
		int x;
		scanf("%d",&x);
		pq.push(x);
	}
	if(N != 1) vote();
	printf("%d", cnt);

	return 0;
}