#include <stdio.h>

int main() {
	int num_input;
	scanf("%d", &num_input);
	int num1, num2;
	num1 = num_input / 10; //초깃값_십의자리
	num2 = (num_input % 10) / 1; //초깃값_일의자리
	int temp1, temp2, temp3; //temp1 십의자리, temp2 일의자리

	temp1 = num2;  
	temp2 = (num1 + num2) % 10 / 1; 
	int count = 1;

	while (!(num1 == temp1 && num2 == temp2)){
		temp3 = temp2;
		temp2 = (temp1 + temp2) % 10 / 1;
		temp1 = temp3;
		count++;
	}
	printf("%d", count);
}