#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for(int tmp=i; tmp<=j; tmp++){
        for(char ch : to_string(tmp)) {
            if(ch-'0' == k) answer++;
        }
    }
    return answer;
}