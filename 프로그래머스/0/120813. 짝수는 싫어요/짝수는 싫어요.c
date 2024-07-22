#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int array_size;
    for(int i = 0; i <= n; i++){
        if(i % 2 == 1) array_size++;
    }
    int* answer = (int*)malloc(array_size * sizeof(int));
    int temp = 0;
    for(int j = 0; j <= n; j++){
        if(j % 2 == 1) {
            answer[temp] = j;
            temp++;
        }
    }
    
    return answer;
}