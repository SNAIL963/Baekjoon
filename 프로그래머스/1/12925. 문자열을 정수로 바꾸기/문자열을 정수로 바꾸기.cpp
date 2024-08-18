#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int temp = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] < '0' || s[i] > '9') {
			break;
		}
		if (s[0] == '-') {
			answer -= (s[i] - 48) * temp;
		}
		else {
			answer += (s[i] - 48) * temp;
		}
		temp *= 10;
	}
	return answer;
}