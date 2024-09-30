#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int evenSum, oddSum;
    for(int i = 0; i< num_list.size(); i++){
        if(i % 2 == 0) evenSum += num_list[i];
        else if(i % 2 == 1) oddSum += num_list[i];
    }
    evenSum > oddSum ? answer = evenSum : answer = oddSum;
    
    return answer;
}