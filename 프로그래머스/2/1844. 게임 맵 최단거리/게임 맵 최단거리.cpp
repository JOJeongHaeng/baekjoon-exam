#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    queue<pair<pair<int, int>, int>> q;
    int m = maps.size();
    int n = maps[0].size();
    vector<pair<int, int>> check = {{1, 0}, {-1,0}, {0, 1}, {0, -1}};
    bool visit[100][100] = {0, };
    
    q.push({{0, 0}, 1});
    visit[0][0] = 1;
    
    while(!q.empty())
    {
        auto [pos, cnt] = q.front();
        auto [y, x] = pos;
        q.pop();
        if(x == n-1 && y == m-1) return cnt;
        for(auto [f, s] : check)
        {
            int nextX = x+f;
            int nextY = y+s;
            if(nextX >= 0 && nextX < n && nextY >=0 && nextY < m && !visit[nextY][nextX] && maps[nextY][nextX] == 1)
            {
                visit[nextY][nextX] = 1;
                q.push({{nextY, nextX}, cnt+1});
            }
        }
    }
    return -1;
}