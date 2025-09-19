#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int>& v1, vector<int>& v2)
{
    if(v1[0] - v1[1] == v2[0] - v2[1]) return v1[0]/v1[1]>v2[0]/v2[1];
    return v1[0] - v1[1] > v2[0] - v2[1];
}

int solution(vector<vector<int>> info, int n, int m) {
    int sn = 0, sm = 0;
    sort(info.begin(), info.end(), cmp);
    for(int i = 0; i<info.size(); i++)
    {
        if(sm + info[i][1] >= m)
        {
            sn+= info[i][0];
            if(sn>=n) return -1;
        }
        else sm += info[i][1];
    }
    return sn;
}