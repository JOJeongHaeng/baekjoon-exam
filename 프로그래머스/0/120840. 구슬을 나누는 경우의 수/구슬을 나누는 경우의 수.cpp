#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    long answer = 1;
    for(int i=0; i<balls-share; i++){
        answer*=balls-i;
        answer/=i+1;
    }
    return answer;
}