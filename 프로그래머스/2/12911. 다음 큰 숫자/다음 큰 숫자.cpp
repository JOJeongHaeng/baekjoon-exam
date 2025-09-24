#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n+1;
    int one = 0;
    while(n != 0)
    {
        if(n%2 == 1) one++;
        n/=2;
    }
    while(true)
    {
        int tmp = answer;
        int count = 0;
        while(tmp != 0)
        {
            if(tmp%2 == 1) count++;
            tmp/=2;
        }
        if(count == one) break;
        else
        {
            answer++;
        }
    }
    return answer;
}