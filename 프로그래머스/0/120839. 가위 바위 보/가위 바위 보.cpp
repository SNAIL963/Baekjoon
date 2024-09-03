#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string rsp) {
    string answer = "";
    
    map<char, char> m;
    
    m.insert({'2','0'});
    m.insert({'0','5'});
    m.insert({'5','2'});
    
    for(int i = 0; i < rsp.size(); i++){
        answer += m[rsp[i]];
    }
    
    return answer;
}