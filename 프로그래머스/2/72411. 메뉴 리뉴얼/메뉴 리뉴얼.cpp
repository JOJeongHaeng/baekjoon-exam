#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(const pair<string, int>& p1, const pair<string, int>& p2)
{
    return p1.second>p2.second;
}

void dfs(const string& order, vector<bool> v, const vector<int>& course, string tmp, map<string, int>& m)
{
    if(tmp.size() >= 2 && tmp.size() <= order.size()) m[tmp]++;
    
    for(int i = 0; i<order.size(); i++)
    {
        if(v[i] != true)
        {
            v[i] = true;
            dfs(order, v, course, tmp+order[i], m);
        }
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m;
    for(int i = 0; i<orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
        vector<bool> v(orders[i].size(), false);
        dfs(orders[i], v, course, "", m);
    }
    vector<pair<string, int>> tmp;
    for(int i : course)
    {
        int biggest = 1;
        pair<string, int> p;
        for(auto a : m)
        {
            if(a.first.size() == i && a.second > biggest)
            {
                biggest = a.second;
                p = a;
            }
        }
        if(biggest != 1) tmp.push_back(p);
    }
    
    for(auto t : tmp)
    {
        for(auto a : m)
        {
            if(a.first.size() == t.first.size() && a.second == t.second) answer.push_back(a.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}