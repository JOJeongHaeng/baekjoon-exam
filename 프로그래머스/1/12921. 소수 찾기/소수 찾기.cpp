#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    if(n == 2) return answer;
    for(int i = 3; i<=n; i++)
    {
        bool check = true;
        for(int j = 2; j*j<=i; j++)
        {
            if(i%j == 0) 
            {
                check = false;
                break;
            }
        }
        if(check) answer++;
    }
    return answer;
}