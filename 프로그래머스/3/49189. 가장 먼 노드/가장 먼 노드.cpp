#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int mx = 0;
    
    vector<vector<int>> v(n + 1);
    vector<int> dist(n + 1, -1);
    for(int i = 0; i<edge.size(); i++)
    {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        
        for(int i = 0; i<v[now].size(); i++)
        {
            if(dist[v[now][i]] != -1) continue;
            dist[v[now][i]] = dist[now] + 1;
            q.push(v[now][i]);
            mx = max(mx, dist[v[now][i]]);
        }
    }
    for(int i = 0; i<dist.size(); i++) if(dist[i] == mx) answer++;
    return answer;
}