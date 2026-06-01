#include <string>
#include <vector>
#include <map>

using namespace std;

bool CanRemove(pair<int, int> p1, pair<int, int> p2, vector<vector<bool>> gmap)
{
    bool flag = true;
    if(p1.second < p2.second) // p1이 p2보다 왼쪽
    {
        for(int i = p1.second + 1; i <= p2.second; i++) // 오른쪽 이동 후 아래로
        {
            if(!gmap[p1.first][i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            for(int i = p1.first + 1; i < p2.first; i++)
            {
                if(!gmap[i][p2.second])
                {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        
        flag = true;
        for(int i = p1.first + 1; i <= p2.first; i++) // 아래로 이동 후 오른쪽
        {
            if(!gmap[i][p1.second])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            for(int i = p1.second + 1; i < p2.second; i++)
            {
                if(!gmap[p2.first][i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
    }
    else
    {
        flag = true;
        for(int i = p1.second - 1; i >= p2.second; i--) //p1이 p2보다 오른쪽
        {
            if(!gmap[p1.first][i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            for(int i = p1.first + 1; i < p2.first; i++) // 왼쪽으로 이동 후 아래로
            {
                if(!gmap[i][p2.second])
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return true;
        flag = true;
        for(int i = p1.first + 1; i <= p2.first; i++)
        {
            if(!gmap[i][p1.second])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            for(int i = p1.second - 1; i > p2.second; i--)
            {
                if(!gmap[p2.first][i])
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return true;
    }
    return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<vector<bool>> gmap(m, vector<bool>(n, false));
    vector<vector<pair<int, int>>> alpha(26);
    int cnt = 0;
    
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(board[i][j] == '.') gmap[i][j] = true;
            else if(isalpha(board[i][j]))
            {
                alpha[board[i][j] - 'A'].push_back({i, j});
                cnt++;
            }
        }
    }
    cnt /= 2;
    
    for(int i = 0; i<cnt; i++)
    {
        bool flag2 = false;
        for(int j = 0; j<26; j++)
        {
            if(alpha[j].size() > 0)
            {
                if(CanRemove(alpha[j][0], alpha[j][1], gmap))
                {
                    flag2 = true;
                    char c = 'A' + j;
                    answer += c;
                    gmap[alpha[j][0].first][alpha[j][0].second] = true;
                    gmap[alpha[j][1].first][alpha[j][1].second] = true;
                    alpha[j] = vector<pair<int, int>>();
                    break;
                }
            }
        }
        if(!flag2)
        {
            return "IMPOSSIBLE";
        }
    }
    
    return answer;
}