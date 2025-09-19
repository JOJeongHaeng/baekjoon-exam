#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& diffs, vector<int>& times, long long limit, int level)
{
    long long answer = 0;
    for(int i=0; i<diffs.size(); i++)
    {
        if(level>=diffs[i]) answer+=times[i];
        else answer += (diffs[i] - level) * (times[i-1] + times[i]) + times[i];
    }
    if(answer > limit) return 0;
    else return 1;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int st = 1;
    int ed = 100000;
    if(check(diffs, times, limit, st)) return 1;
    while(st+1 < ed)
    {
        int mid = (st+ed)/2;
        if(check(diffs, times, limit, mid)) ed = mid;
        else st = mid;
    }
        
    return ed;
}