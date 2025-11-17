#include <string>
#include <vector>

using namespace std;

bool check(int y, int x, vector<vector<pair<char, bool>>>& v, int& count)
{
    bool ans = false;
    if(y+1 < v.size() && x+1 < v[0].size())
    {
        if(v[y][x].first != ' ' && v[y][x].first == v[y+1][x].first && v[y][x].first == v[y][x+1].first && v[y][x].first == v[y+1][x+1].first)
        {
            if(v[y][x].second)
            {
                count++;
            }
            if(v[y+1][x].second)
            {
                count++;
            }
            if(v[y][x+1].second)
            {
                count++;
            }
            if(v[y+1][x+1].second)
            {
                count++;
            }
            
            v[y][x].second = false;
            v[y+1][x].second = false;
            v[y][x+1].second = false;
            v[y+1][x+1].second = false;
            
            ans = true;
        }
    }
    return ans;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<pair<char, bool>>> v(m, vector<pair<char, bool>>(n, make_pair('b', true)));
    for(int y = 0; y<m; y++)
    {
        for(int x = 0; x<n; x++)
        {
            v[y][x] = make_pair(board[y][x], true);
        }
    }
    
    bool c = true;
    while(c)
    {
        c = false;
        for(int y = 0; y<m-1; y++)
        {
            for(int x = 0; x<n-1; x++)
            {
                bool b = check(y, x, v, answer);
                if(b) c = b;
            }
        }
        
        for(int y = m-1; y >= 0; y--)
        {
            for(int x = n-1; x >= 0; x--)
            {
                if(v[y][x].second == false)
                {
                    v[y][x] = {' ', false};
                    for(int h = y-1; h>=0; h--)
                    {
                        if(v[h][x].second != false)
                        {
                            v[y][x] = v[h][x];
                            v[h][x] = {' ', false};
                            break;
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}