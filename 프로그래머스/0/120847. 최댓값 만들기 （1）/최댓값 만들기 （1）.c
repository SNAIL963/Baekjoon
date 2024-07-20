#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    for(int i=0; i<numbers_len; i++){
        int temp=0;
        for(int j=0; j<numbers_len-1; j++){
            temp = numbers[j];
            if(temp > numbers[j+1]){
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    answer = numbers[numbers_len-2] * numbers[numbers_len-1];
    
    return answer;
}