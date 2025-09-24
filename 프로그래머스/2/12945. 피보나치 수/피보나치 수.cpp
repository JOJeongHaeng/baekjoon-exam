#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long first = 1;
    long long second = 1;
    for(int i = 3; i<=n; i++)
    {
        long long tmp = second;
        second = (first+second)%1234567;
        first = tmp%1234567;
    }
    return second;
}