#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

string solution(string s) {
    string answer = " ";
    s[0] = toupper(s[0]); 
    for (int i = 1; i < s.size(); i++){
       if(isupper(s[i])) {
           s[i] = tolower(s[i]);
               
       }
       if(s[i - 1] == ' ') {
           s[i] = toupper(s[i]);
       }
    }
    answer = s;
    return answer;
}