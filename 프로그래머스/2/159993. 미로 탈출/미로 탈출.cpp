#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> start;
    // 시작 지점
    for(int i = 0; i<maps.size(); i++)
    {
        for(int j = 0; j<maps[0].size(); j++)
        {
            if(maps[i][j] == 'S')
            {
                start = {i, j};
                break;
            }
        }
    }
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), 0));
    visit[start.first][start.second] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push({{start.first, start.second}, 0});
    int min = INT_MAX;
    
    pair<int, int> Lever;
    
    while(!q.empty())
    {
        auto info = q.front();
        int y = info.first.first;
        int x = info.first.second;
        int cnt = info.second;
        q.pop();
        if(maps[y][x] == 'L')
        {
            if(min > cnt)
            {
                min = cnt;
                Lever = {y, x};
            }
        }
        if(y-1 >= 0 && maps[y-1][x] != 'X' && !visit[y-1][x])
        {
            visit[y-1][x] = true;
            q.push({{y-1, x}, cnt+1});
        }
        if(y+1 < maps.size() && maps[y+1][x] != 'X' && !visit[y+1][x])
        {
            visit[y+1][x] = true;
            q.push({{y+1, x}, cnt+1});
        }
        if(x-1 >= 0 && maps[y][x-1] != 'X' && !visit[y][x-1])
        {
            visit[y][x-1] = true;
            q.push({{y, x-1}, cnt+1});
        }
        if(x+1 < maps[0].size() && maps[y][x+1] != 'X' && !visit[y][x+1])
        {
            visit[y][x+1] = true;
            q.push({{y, x+1}, cnt+1});
        }
    }
    
    if(min == INT_MAX) return -1;
    int tmp = min;
    min = INT_MAX;
    q.push({Lever, 0});
    for(auto& row : visit) fill(row.begin(), row.end(), 0);
    visit[Lever.first][Lever.second] = true;
    
    while(!q.empty())
    {
        auto info = q.front();
        int y = info.first.first;
        int x = info.first.second;
        int cnt = info.second;
        q.pop();
        if(maps[y][x] == 'E')
        {
            if(min > cnt)
            {
                min = cnt;
                Lever = {y, x};
            }
        }
        if(y-1 >= 0 && maps[y-1][x] != 'X' && !visit[y-1][x])
        {
            visit[y-1][x] = true;
            q.push({{y-1, x}, cnt+1});
        }
        if(y+1 < maps.size() && maps[y+1][x] != 'X' && !visit[y+1][x])
        {
            visit[y+1][x] = true;
            q.push({{y+1, x}, cnt+1});
        }
        if(x-1 >= 0 && maps[y][x-1] != 'X' && !visit[y][x-1])
        {
            visit[y][x-1] = true;
            q.push({{y, x-1}, cnt+1});
        }
        if(x+1 < maps[0].size() && maps[y][x+1] != 'X' && !visit[y][x+1])
        {
            visit[y][x+1] = true;
            q.push({{y, x+1}, cnt+1});
        }
    }
    if(min == INT_MAX) return -1;
    return tmp+min;
}