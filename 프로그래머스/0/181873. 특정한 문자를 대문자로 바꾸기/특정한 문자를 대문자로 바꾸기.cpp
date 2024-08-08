#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string my_string, string alp) {
    string answer = "";
    char c = alp[0];
    for(int i=0; i < my_string.size(); i++){
        if(my_string[i] == c){
            my_string[i] -= 32;
        }
    }
    answer = my_string;
    
    return answer;
}