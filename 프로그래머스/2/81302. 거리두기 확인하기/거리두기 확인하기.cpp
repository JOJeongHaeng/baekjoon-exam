#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check(const vector<string>& place, pair<pair<int, int>, int>& p, vector<vector<bool>> visited)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(p);
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    while(!q.empty())
    {
        auto info = q.front();
        q.pop();
        auto pos = info.first;
        int y = pos.first;
        int x = pos.second;
        int cnt = info.second;
        visited[y][x] = true;

        for(auto d : dir)
        {
            if(y+d.first >= 0 && y+d.first < place.size() 
               && x+d.second >= 0 && x+d.second < place[0].size() 
               && place[y+d.first][x+d.second] != 'X' && !visited[y+d.first][x+d.second])
            {
                if(place[y+d.first][x+d.second] == 'P') return false;
                else if(cnt < 1)
                {
                    q.push({{y+d.first, x+d.second}, cnt+1});
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    vector<vector<bool>> visited(places[0].size(), vector<bool>(places[0][0].size(), false));
    for(auto place : places)
    {
        bool isokay = true;
        for(int i = 0; i<place.size(); i++)
        {
            for(int j = 0; j<place[0].size(); j++)
            {
                if(place[i][j] == 'P')
                {
                    pair<pair<int, int>, int> info = make_pair(make_pair(i, j), 0);
                    if(!check(place, info, visited)) isokay = false;
                }
            }
        }
        if(isokay) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}