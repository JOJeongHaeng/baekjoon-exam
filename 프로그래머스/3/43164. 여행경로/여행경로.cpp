#include <string>
#include <vector>

using namespace std;

vector<string> answer;
bool visited[10000] = {false, };

bool cmp(vector<string> v1, vector<string> v2)
{
    for(int i = 0; i<v1.size(); i++)
    {
        if(v1[i] == v2[i]) continue;
        else if(v1[i] < v2[i]) return true;
        else return false;
    }
    return true;
}

void dfs(string str, int cnt, const vector<vector<string>>& tickets, vector<string> now)
{
    if(cnt == tickets.size())
    {
        if(answer.empty()) answer = now;
        else
        {
            if(!cmp(answer, now)) answer = now;
        }
        return;
    }
    
    for(int i = 0; i<tickets.size(); i++)
    {
        if(!visited[i] && tickets[i][0] == str)
        {
            visited[i] = true;
            now.push_back(tickets[i][1]);
            dfs(tickets[i][1], cnt + 1, tickets, now);
            visited[i] = false;
            now.pop_back();
        }
    }
}
    
vector<string> solution(vector<vector<string>> tickets) {
    for(int i = 0; i<tickets.size(); i++)
    {
        if(tickets[i][0] == "ICN")
        {
            vector<string> tmp = {"ICN"};
            tmp.push_back(tickets[i][1]);
            visited[i] = true;
            dfs(tickets[i][1], 1, tickets, tmp);
            visited[i] = false;
        }
    }
    
    return answer;
}