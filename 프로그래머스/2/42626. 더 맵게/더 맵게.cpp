#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(), scoville.end(), greater<int>());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    while(!pq.empty())
    {
        int first = pq.top();
        pq.pop();
        if(first >= K) return answer;
        if(pq.empty()) return -1;
        int second = pq.top();
        pq.pop();
        pq.push(first+(second*2));
        answer++;
    }
    return -1;
}