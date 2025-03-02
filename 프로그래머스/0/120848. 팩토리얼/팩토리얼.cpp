#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int tmp = 1;
    while(tmp*answer<=n){
        tmp*=answer;
        answer++;
    }
    return --answer;
}