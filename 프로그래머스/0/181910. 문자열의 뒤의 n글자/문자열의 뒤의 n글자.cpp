#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    int temp = my_string.length() - n;
    for(int i = temp; i < my_string.length(); i++){
        answer += my_string[i];
    }
    return answer;
}