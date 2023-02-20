#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define ull unsigned long long

using namespace std;

ull binarySearch(ull n) {
	ull left = 1;
	ull right = sqrt(n) * 2;
	ull middle = 0;
	ull ans = 0;
	while (left <= right) {
		middle = (left + right) / 2;
		if (middle * (middle + 1) <= 2 * n) ans = max(ans, middle), left = middle + 1;
		else right = middle - 1;
	}
	return ans;
}
int main() {
	ull t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << binarySearch(n) << '\n';
	}
}