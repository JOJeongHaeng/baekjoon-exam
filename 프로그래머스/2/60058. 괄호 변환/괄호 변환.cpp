#include <string>
#include <vector>

using namespace std;

bool check(string str)
{
    int cnt = 0;
    for(char c : str)
    {
        if(cnt == -1) return false;
        if(c == '(') cnt++;
        else cnt--;
    }
    if(cnt == 0) return true;
    else return false;
}

int num = 1;

string dfs(string str)
{
    if(str.empty()) return "";
    
    string tmp = "";
    string u = "";
    string v = "";
    int cnt = 0;
    
    if(str[0] == '(') cnt++;
    else cnt--;
    u+=str[0];
    
    for(int i = 1; i<str.size(); i++)
    {
        if(cnt!=0)
        {
            if(str[i] == '(') cnt++;
            else cnt--;
            u+=str[i];
        }
        else
        {
            v = str.substr(i);
            break;
        }
    }
    
    if(check(u))
    {
        tmp = u+dfs(v);
        return tmp;
    }
    else
    {
        u = u.substr(1, u.size()-2);
        for(int i = u.size()-1; i>=0; i--)
        {
            if(u[i] == ')') u[i] = '(';
            else u[i] = ')';
        }
        tmp = "("+dfs(v)+")"+u;
        return tmp;
    }
}



string solution(string p) {
    string answer = "";
    answer = dfs(p);
    
    return answer;
}