#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void dfs(const vector<string>& maps, const vector<pair<int, int>>& dir,
         vector<vector<bool>>& visit, pair<int, int> pos, int& cnt)
{
    int y = pos.first, x = pos.second;
    
    for(auto p : dir)
    {
        if(0 <= y+p.first && y+p.first < maps.size() && 0 <= x+p.second && x+p.second < maps[0].size() && maps[y+p.first][x+p.second] != 'X')
        {
            if(!visit[y+p.first][x+p.second])
            {
                visit[y+p.first][x+p.second] = true;
                cnt+=(maps[y+p.first][x+p.second] - '0');
                dfs(maps, dir, visit, {y+p.first, x+p.second}, cnt);
            }
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int H = maps.size();
    int W = maps[0].size();
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visit(H, vector<bool>(W, false));
    
    for(int i = 0; i<H; i++)
    {
        for(int j = 0; j<W; j++)
        {
            if(maps[i][j] != 'X' && !visit[i][j])
            {
                visit[i][j] = true;
                int cnt = maps[i][j] - '0';
                dfs(maps, dir, visit, {i, j}, cnt);
                answer.push_back(cnt);
            }
        }
    }
    if(answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}