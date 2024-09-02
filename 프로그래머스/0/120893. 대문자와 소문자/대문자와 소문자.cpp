#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(int i = 0; i < my_string.size(); i++){
        if(65 <= my_string[i] && 90 >= my_string[i] ){
            answer += tolower(my_string[i]);
        }
        else if(97 <= my_string[i] && 122 >= my_string[i] ){
            answer += toupper(my_string[i]);
        }
    }
    return answer;
}