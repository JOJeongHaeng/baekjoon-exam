#include <string>
#include <vector>
using namespace std;

bool cmp(const vector<int>& v1, const vector<int>& v2, int col)
{
    if(v1[col] == v2[col]) return v1[0] >= v2[0];
    return v1[col] < v2[col];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    for(int i = 0; i<data.size(); i++)  // col값 기준으로 오름차순 정렬
    {
        for(int j = data.size()-1; j>=1; j--)
        {
            int k = j-1;
            if(!cmp(data[k], data[j], col-1)) swap(data[k], data[j]);
        }
    }
    
    vector<int> sum_v;
    for(int i = row_begin; i<=row_end; i++)
    {
        int S_i = 0;
        for(int num : data[i-1])
        {
            S_i += num%i;
        }
        sum_v.push_back(S_i);
    }
    
    answer = sum_v[0];
    for(int i = 1; i<sum_v.size(); i++)
    {
        answer ^= sum_v[i];
    }
    return answer;
}