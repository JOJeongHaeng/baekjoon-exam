#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string calculator(string str1, string oper, string str2)
{
    if(oper == "*") return to_string(stoll(str1) * stoll(str2));
    else if(oper == "+") return to_string(stoll(str1) + stoll(str2));
    else return to_string(stoll(str1) - stoll(str2));
}

void f(const vector<char>& oper, vector<string> v, long long& max)
{
    int vsize = v.size();
    for(int idx = 0; idx<vsize; idx++)
    {
        if(v[idx] == string(1, oper[0]))
        {
            v[idx-1] = calculator(v[idx-1], v[idx], v[idx+1]);
            v.erase(v.begin()+idx, v.begin()+idx+2);
            vsize -= 2;
            idx--;
        }
    }
    
    for(int idx = 0; idx<vsize; idx++)
    {
        if(v[idx] == string(1, oper[1]))
        {
            v[idx-1] = calculator(v[idx-1], v[idx], v[idx+1]);
            v.erase(v.begin()+idx, v.begin()+idx+2);
            vsize -= 2;
            idx--;
        }
    }
    
    for(int idx = 0; idx<vsize; idx++)
    {
        if(v[idx] == string(1, oper[2]))
        {
            v[idx-1] = calculator(v[idx-1], v[idx], v[idx+1]);
            v.erase(v.begin()+idx, v.begin()+idx+2);
            vsize -= 2;
            idx--;
        }
    }
    
    long long tmp = stoll(v[0]);
    
    if(tmp<0) tmp = -tmp;
    if(max < tmp) max = tmp;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<vector<char>> opers = {{'*', '+', '-'}, {'*', '-', '+'}, 
                                  {'+', '-', '*'}, {'+', '*', '-'}, 
                                  {'-', '*', '+'}, {'-',  '+', '*'}};
    vector<string> v;
    string tmp = "";
    for(char c : expression)
    {
        if(isdigit(c)) tmp+=c;
        else
        {
            v.push_back(tmp);
            v.push_back(string(1, c));
            tmp = "";
        }
    }
    v.push_back(tmp);
    
    long long max = 0;
    for(auto oper : opers)
    {
        f(oper, v, max);
    }
    return max;
}