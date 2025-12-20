#include <string>
#include <vector>

using namespace std;

void RF(int n, int from, int tmp, int to, vector<vector<int>>& answer)
{
    vector<int> v;
    if(n == 1)
    {
        v.push_back(from);
        v.push_back(to);
        answer.push_back(v);
    }
    else
    {
        RF(n-1, from, to, tmp, answer);
        
        v.push_back(from);
        v.push_back(to);
        answer.push_back(v);
        
        RF(n-1, tmp, from, to, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    RF(n, 1,2,3, answer);
    return answer;
}