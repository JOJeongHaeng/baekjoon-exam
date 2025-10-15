#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i = left; i<=right; i++)
    {
        int row = i/n;
        int idx = i%n;
        if(row >= idx) answer.push_back(row+1);
        else answer.push_back(idx+1);
    }
    return answer;
}