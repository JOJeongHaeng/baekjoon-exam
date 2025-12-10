#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    pair<int, int> start;
    for(int i = 0; i<board.size(); i++)
    {
        for(int j = 0; j<board[i].size(); j++)
        {
            if(board[i][j] == 'R') 
            {
                start = {i, j};
                visited[i][j] = true;
                break;
            }
        }
    }
    
    queue<pair<pair<int, int>, int> > q;
    q.push({start, 1});
    
    while(!q.empty())
    {
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i = 0; i<dir.size(); i++)
        {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int cnt = q.front().second;
            while(0 <= y+dir[i].first && y+dir[i].first < board.size() && 0 <= x+dir[i].second && x+dir[i].second < board[0].size() && board[y+dir[i].first][x+dir[i].second] != 'D')
            {
                y+=dir[i].first;
                x+=dir[i].second;
            }
            if(board[y][x] == 'G')
            {
                return cnt;
            }
            if(visited[y][x] != true)
            {
                visited[y][x] = true;
                q.push({{y, x}, cnt+1});
            }
        }
        q.pop();
    }
    return answer;
}