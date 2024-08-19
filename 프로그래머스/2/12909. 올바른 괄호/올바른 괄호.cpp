#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	vector <char> cv;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cv.push_back('(');
		}
		else if ( s[i] == ')') {
			if (!cv.empty()) {
				cv.pop_back();
			}
			else if (cv.empty()) {
				answer = false;
				return answer; 
			}
		}
	}

	if (!cv.empty()) answer = false;

	return answer;
}