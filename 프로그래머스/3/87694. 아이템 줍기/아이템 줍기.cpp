#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int map[102][102] = {0, };
    bool visited[102][102] = {false, };
    
    for(int i = 0; i<rectangle.size(); i++)
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for(int x = x1; x<=x2; x++)
        {
            for(int y = y1; y<=y2; y++)
            {
                map[x][y] = 1;
            }
        }
    }
    for(int i = 0; i<rectangle.size(); i++)
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for(int x = x1+1; x<x2; x++)
        {
            for(int y = y1+1; y<y2; y++)
            {
                map[x][y] = 0;
            }
        }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{characterX * 2, characterY * 2}, 0});
    visited[characterX * 2][characterY * 2] = true;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    while(!q.empty())
    {
        auto pp = q.front();
        auto pos = pp.first;
        int cnt = pp.second;
        
        if(pos.first == itemX * 2 && pos.second == itemY * 2)
        {
            answer = cnt / 2;
            break;
        }
        q.pop();
        
        for(int i = 0; i<4; i++)
        {
            if(!visited[pos.first + dx[i]][pos.second + dy[i]] && map[pos.first + dx[i]][pos.second + dy[i]] == 1)
            {
                q.push({{pos.first + dx[i], pos.second + dy[i]}, cnt + 1});
                visited[pos.first + dx[i]][pos.second + dy[i]] = true;
            }
        }
    }
    
    return answer;
}