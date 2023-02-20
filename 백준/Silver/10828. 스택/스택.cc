#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int main(void) {
	stack <int> st;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int x;
			cin >> x;
			st.push(x);
		}
		else if (str == "pop") {
			if (st.empty())
				cout << "-1" << endl;
			else {
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (str == "top") {
			if (st.empty())
				cout << "-1" << endl;
			else
				cout << st.top() << endl;
		}
		else if (str == "size") {
			cout << st.size() << endl;
		}
		else if (str == "empty") {
			cout << st.empty() << endl;
		}
	}

	return 0;
}