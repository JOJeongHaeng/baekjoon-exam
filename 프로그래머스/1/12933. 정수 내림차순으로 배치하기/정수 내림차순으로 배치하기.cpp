#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(long long n) {
    map<long long, long long> m;
    while(n>0)
    {
        m[n%10]++;
        n/=10;
    }
    long long answer = 0;
    int num = 1;
    for(auto iter : m)
    {
        for(int i = 0; i<iter.second; i++)
        {
            answer+=iter.first*num;
            num*=10;
        }
    }
    return answer;
}