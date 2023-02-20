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

using namespace std;

string MBTI;

int main(void) {
	cin >> MBTI;

	if (MBTI[0] == 'I') MBTI[0] = 'E';
	else MBTI[0] = 'I';
	if (MBTI[1] == 'S') MBTI[1] = 'N';
	else MBTI[1] = 'S';	
	if (MBTI[2] == 'T') MBTI[2] = 'F';
	else MBTI[2] = 'T';	
	if (MBTI[3] == 'J') MBTI[3] = 'P';
	else MBTI[3] = 'J';

	cout << MBTI;

	return 0;
}