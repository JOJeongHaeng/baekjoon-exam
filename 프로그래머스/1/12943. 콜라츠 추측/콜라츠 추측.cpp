#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    long long n = static_cast<long long>(num);
    int answer = 0;
    while(n != 1)
    {
        if(n%2 == 0) n/=2;
        else n = (n*3)+1;
        answer++;
        if(answer == 501) return -1;
    }
    return answer;
}