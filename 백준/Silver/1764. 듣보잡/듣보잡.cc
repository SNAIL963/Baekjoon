#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
	int N, M;
	vector <string> v;
	vector <string> v2;
	scanf("%d %d", &N, &M);

	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int count = 0;

	for (int i = 0; i < M; i++) {
		string a;
		cin >> a;
		if (binary_search(v.begin(), v.end(), a)) {
			count++;
			v2.push_back(a);
		}
	}

	int x = v2.size();
	sort(v2.begin(), v2.end());
	printf("%d\n", x);
	for (int i = 0; i < x; i++) {
		cout << v2[i] << endl;
	}

	return 0;
}