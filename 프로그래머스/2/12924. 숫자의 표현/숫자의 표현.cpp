#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sumnum = 0;
    int idx = 1;
    for(int i = 1; i<=n+1;)
    {
        if(sumnum < n)
        {
            sumnum+=i;
            i++;
        }
        else if(sumnum == n) 
        {
            answer++;
            sumnum = 0;
            i = ++idx;
        }
        else
        {
            sumnum = 0;
            i = ++idx;
        }
    }
    return answer;
}