#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    string temp;
    
    temp = to_string(a) + to_string(b);
    
    if(stoi(temp) > a * b * 2){
        answer = stoi(temp);
    }
    else {
        answer = a * b * 2;
    }
    
    return answer;
}