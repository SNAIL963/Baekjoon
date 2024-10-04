#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    int t;
    for(int i = 0; i < n_str.size(); i++){
        if(n_str[i] != '0') {
            t = i;
            break;
        }
    }
    for(int j = t; j < n_str.size(); j++){
        answer += n_str[j];
    }
    
    return answer;
}