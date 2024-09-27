#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    string tempA, tempB;
    
    tempA = to_string(a) + to_string(b);
    tempB = to_string(b) + to_string(a);
    
    if(stoi(tempA) > stoi(tempB)){
        answer = stoi(tempA);
    } else{
        answer = stoi(tempB);
    }
    
    return answer;
}