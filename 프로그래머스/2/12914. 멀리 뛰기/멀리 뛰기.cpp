#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long arr[2000];
    for(int i = 1; i<=n; i++)
    {
        if(i == 1) arr[1] = 1;
        else if(i == 2) arr[2] = 2;
        else
        {
            arr[i] = (arr[i-1] + arr[i-2]) % 1234567;
        }
    }
    answer = arr[n];
    return answer;
}