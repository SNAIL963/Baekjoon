#include <iostream>

using namespace std;

int main() {
	int num[9];
	for (int i = 0; i < 9; i++)
		cin >> num[i];
	int max = num[0];
	int max_index = 1;
	for (int i = 0; i < 9; i++) {
		if (max < num[i])
			max = num[i];
	}
	for (int i = 0; i < 9; i++) {
		if (max == num[i])
			max_index = i+1;
	}
	cout << max << endl; 
	cout << max_index;
	
	return 0;
}