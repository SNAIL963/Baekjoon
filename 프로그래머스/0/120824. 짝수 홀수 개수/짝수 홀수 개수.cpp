#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int o = 0;
    int e = 0;
    for(int i=0; i< num_list.size(); i++){
        if(num_list[i] % 2 == 1) o++;
        else e++;
    }
    answer.push_back(e);
    answer.push_back(o);
    return answer;
}