#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int answer = 51;

bool check(string str1, string str2)
{
    int tmp = 0;
    for(int i = 0; i<str1.size(); i++)
    {
        if(str1[i] != str2[i])
        {
            tmp++;
            if(tmp == 2) return false;
        }
    }
    if(tmp == 1) return true;
    return false;
}

void dfs(string now, const string& target, int cnt, bool visited[], const vector<string>& words)
{
    if(now == target)
    {
        answer = min(answer, cnt);
        return;
    }
    for(int i = 0; i<words.size(); i++)
    {
        if(!visited[i] && check(now, words[i]))
        {
            visited[i] = true;
            dfs(words[i], target, cnt + 1, visited, words);
            visited[i] = false;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    bool visited[51] = {false, };
    
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    for(int i = 0; i<words.size(); i++)
    {
        if(check(begin, words[i]))
        {
            visited[i] = true;
            dfs(words[i], target, 1, visited, words);
            visited[i] = false;
        }
    }
    if(answer == 51) return 0;
    return answer;
}