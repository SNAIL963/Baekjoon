#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int ns = num_list.size();
    if (num_list[ns - 1] > num_list[ns - 2]){
        num_list.push_back(num_list[ns - 1] - num_list[ns - 2]);
    }
    else{
        num_list.push_back(num_list[ns - 1] * 2);
    }

    return num_list;
}