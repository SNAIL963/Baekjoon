#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mid;
vector<int> sgCard;
int card(int left, int right, int num) {
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (num == sgCard[mid]) return 1;
		else if (num > sgCard[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return 0;
}

int main() {
	int n, sg, m, num;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sg);
		sgCard.push_back(sg);
	}
	sort(sgCard.begin(), sgCard.end());
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		printf("%d ", card(0, n - 1, num));
	}
}