#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct compare
{
    bool operator()(vector<int> v1, vector<int> v2){
        return v1[1] > v2[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int idx = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    while(!pq.empty() || idx < jobs.size())
    {
        if(idx < jobs.size() && jobs[idx][0] <= time)
        {
            pq.push(jobs[idx++]);
            continue;
        }
        
        if(!pq.empty())
        {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
        {
            time = jobs[idx][0];
        }
    }
    
    return answer/jobs.size();
}