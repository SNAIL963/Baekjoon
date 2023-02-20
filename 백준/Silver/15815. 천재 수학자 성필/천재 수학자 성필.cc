#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int main(void) {
	stack <int> number;

	char c;
	int a, b;

	while (1) {
		scanf("%c", &c);
		if (c == '\n')
			break;
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			a = number.top();
			number.pop();
			b = number.top();
			number.pop();
			switch (c) {
			case '+':
				number.push(b + a);
				break;
			case '-':
				number.push(b - a);
				break;
			case '*':
				number.push(b * a);
				break;
			case '/':
				number.push(b / a);
				break;
			default:
				break;
			}
		}
		else
			number.push(c - 48);
	}
	printf("%d", number.top());

	return 0;
}