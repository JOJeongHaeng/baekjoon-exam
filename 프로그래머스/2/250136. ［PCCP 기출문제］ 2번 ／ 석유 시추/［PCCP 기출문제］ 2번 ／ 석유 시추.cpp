#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dfs(vector<vector<int>>& land, vector<vector<bool>>& visited, vector<vector<int>>& dommymap, pair<int, int> pos, int idx, int& cnt)
{
    for(int i = 0; i<4; i++)
    {
        int ny = pos.first + dy[i];
        int nx = pos.second + dx[i];
        if(ny < 0 || nx < 0 || ny >= land.size() || nx >= land[0].size()) continue;
        
        if(!visited[ny][nx] && land[ny][nx])
        {
            visited[ny][nx] = true;
            dommymap[ny][nx] = idx;
            cnt++;
            dfs(land, visited, dommymap, {ny, nx}, idx, cnt);
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    map<int, int> oilcnt;
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dommymap(n, vector<int>(m, 0));
    
    int idx = 1;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(!visited[i][j] && land[i][j] == 1)
            {
                int cnt = 1;
                visited[i][j] = true;
                dommymap[i][j] = idx;
                dfs(land, visited, dommymap, {i, j}, idx, cnt);
                oilcnt[idx++] = cnt;
            }
        }
    }
    for(int i = 0; i<m; i++)
    {
        int tmp = 0;
        set<int> s;
        for(int j = 0; j<n; j++)
        {
            if(dommymap[j][i] != 0) 
            {
                s.insert(dommymap[j][i]);
            }
        }
        for(int num : s)
        {
            tmp += oilcnt[num];
        }
        answer = max(answer, tmp);
    }
    return answer;
}