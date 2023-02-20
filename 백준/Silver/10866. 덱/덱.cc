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

int main(void) {
	deque <int> dq;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push_front") {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (str == "pop_front") {
			if (dq.empty())
				cout << "-1" << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.empty())
				cout << "-1" << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (str == "size") {
			cout << dq.size() << endl;
		}
		else if (str == "empty") {
			cout << dq.empty() << endl;
		}
		else if (str == "front") {
			dq.empty() ? cout << "-1" << endl : cout << dq.front() << endl;
		}
		else if (str == "back") {
			dq.empty() ? cout << "-1" << endl : cout << dq.back() << endl;
		}
	}
	return 0;
}