#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    answer = answer + hp / 5 + hp % 5 / 3 + hp % 5 % 3 / 1;
    return answer;
}