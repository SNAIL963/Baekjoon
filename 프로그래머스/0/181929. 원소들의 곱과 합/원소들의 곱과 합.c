#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    int a = 0;
    int b = 1;
    for(int i = 0; i < num_list_len; i++){
        a += num_list[i];
        b *= num_list[i];
    }
    if(a * a > b) answer = 1;
    return answer;
}