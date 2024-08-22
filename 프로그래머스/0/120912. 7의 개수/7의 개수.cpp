#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(int i : array){
        string temp = to_string(i);
        for(int j = 0; j < temp.length(); j++){
            if (temp[j] == '7') answer++;
        }
    }
    return answer;
}