#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    istringstream ss(s);
    int n;
    vector<int> num;
    
    string word;
    while (ss >> word) {
        num.push_back(stoi(word));
    }
    
    sort(num.begin(), num.end());
    
    answer = to_string(num[0]) + ' ' + to_string(num[num.size()-1]);
    
    return answer;
}