#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

stack <int> one;
stack <int> two;
stack <int> three;
stack <int> four;
stack <int> five;
stack <int> six;

int main(void) {
	int N, P;
	scanf("%d %d", &N, &P);

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int line, pret;
		scanf("%d %d", &line, &pret);

		switch (line) {
		case 1:
			while (1) {
				if (one.empty()) {
					one.push(pret);
					ans++;
					break;
				}
				else if (one.top() > pret) {
					one.pop();
					ans++;
				}
				else if (one.top() < pret) {
					one.push(pret);
					ans++;
					break;
				}
				else break;
			}
			break;
		case 2:
			while (1) {
				if (two.empty()) {
					two.push(pret);
					ans++;
					break;
				}
				else if (two.top() > pret) {
					two.pop();
					ans++;
				}
				else if (two.top() < pret) {
					two.push(pret);
					ans++;
					break;
				}
				else break;
			}
			break;
		case 3:
			while (1) {
				if (three.empty()) {
					three.push(pret);
					ans++;
					break;
				}
				else if (three.top() > pret) {
					three.pop();
					ans++;
				}
				else if (three.top() < pret) {
					three.push(pret);
					ans++;
					break;
				}
				else break;
			}
			break;
		case 4:
			while (1) {
				if (four.empty()) {
					four.push(pret);
					ans++;
					break;
				}
				else if (four.top() > pret) {
					four.pop();
					ans++;
				}
				else if (four.top() < pret) {
					four.push(pret);
					ans++;
					break;
				}
				else break;
			}
			break;
		case 5:
			while (1) {
				if (five.empty()) {
					five.push(pret);
					ans++;
					break;
				}
				else if (five.top() > pret) {
					five.pop();
					ans++;
				}
				else if (five.top() < pret) {
					five.push(pret);
					ans++;
					break;
				}
				else break;
			}
			break;
		case 6:
			while (1) {
				if (six.empty()) {
					six.push(pret);
					ans++;
					break;
				}
				else if (six.top() > pret) {
					six.pop();
					ans++;
				}
				else if (six.top() < pret) {
					six.push(pret);
					ans++;
					break;
				}
				else break;
			}
			break;
		}
	}
	printf("%d", ans);

	return 0;
}