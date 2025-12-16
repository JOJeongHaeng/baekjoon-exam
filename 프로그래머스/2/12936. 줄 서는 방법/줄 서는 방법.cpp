#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    long long fact[n+1];
    long long num = 1;
    fact[0] = 1;
    vector<int> arr;
    for(int i = 1; i<=n; i++)
    {
        num *= i;
        fact[i] = num;
        arr.push_back(i);
    }
    
    int cnt = 1;
    while(cnt < n)
    {
        long long tmp = fact[n-cnt];
        int idx = (k-1)/tmp;
        answer.push_back(arr[idx]);
        arr.erase(arr.begin() + idx);
        k = k%tmp == 0 ? tmp : k%tmp;
        cnt++;
    }
    answer.push_back(arr[0]);
    return answer;
}