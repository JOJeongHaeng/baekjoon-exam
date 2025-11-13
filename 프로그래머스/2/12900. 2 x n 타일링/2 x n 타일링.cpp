#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if(n == 1) answer = 1;
    else if(n == 2) answer = 2;
    int pre = 1;
    int now = 2;
    
    for(int i = 3; i<=n; i++)
    {
        answer = (pre + now) % 1000000007;
        pre = now;
        now = answer;
    }
    return answer;
}