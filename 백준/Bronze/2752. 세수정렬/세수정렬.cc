#include <iostream>

using namespace std;

int main() {
	int num_in[3], num_out[3];
	cin >> num_in[0] >> num_in[1] >> num_in[2];
	int min = num_in[0]; 
	int min_index = 0;
	for (int i = 0; i < 3; i++) {
		if (num_in[i] < min) {
			min = num_in[i];
			min_index = i;
		}
	}
	num_out[0] = min;
	for (int i = 0; i < 3; i++) {
		if (i < min_index)
			num_out[i + 1] = num_in[i];
		else if (i > min_index)
			num_out[i] = num_in[i];
	}
	if (num_out[1] > num_out[2]) {
		int temp;
		temp = num_out[1];
		num_out[1] = num_out[2];
		num_out[2] = temp;
	}
	for (int i = 0; i < 3; i++) {
		printf("%d ",num_out[i]);
	}
	return 0;
}