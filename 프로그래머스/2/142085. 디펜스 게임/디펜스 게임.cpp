#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = -1;
    int idx = 0;
    int max_i = 0;
    priority_queue<int> pq;
    while(n >= 0 && idx <= enemy.size())
    {
        answer++;
        n-=enemy[idx];
        pq.push(enemy[idx]);
        if(n<0)
        {
            if(k>0)
            {
                n += pq.top();
                pq.pop();
                k--;
            }
            else
            {
                return answer;
            }
        }
        idx++;
    }
    
    return enemy.size();
}