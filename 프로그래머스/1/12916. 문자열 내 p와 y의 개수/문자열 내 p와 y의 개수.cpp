#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int pNum = 0;
    int yNum = 0;
    
    for(char c : s){
        if(c == 'p' || c == 'P') pNum++;
        else if(c == 'y' || c == 'Y') yNum++;
    }
    
    if(pNum != yNum) answer = false;

    return answer;
}