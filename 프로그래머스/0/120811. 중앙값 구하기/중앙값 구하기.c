#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;
    for(int i=0; i<array_len; i++){
        int temp=0;
        for(int j=0; j<array_len-1; j++){
            temp = array[j];
            if(temp > array[j+1]){
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    answer = array[array_len/2];
    
    return answer;
}