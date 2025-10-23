#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int> p1, pair<int, int> p2)
{
    if(p1.second == p2.second) return p1.first > p2.first;
    return p1.second > p2.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> um;
    
    string tmp;
    for(char c : s)
    {
        if(isdigit(c))
        {
            tmp += c;
        }
        else if(tmp.size()!=0)
        {
            um[stoi(tmp)]++;
            tmp = "";
        }
    }
    vector<pair<int, int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), comp);
    for(auto p : v)
    {
        answer.push_back(p.first);
    }
    
    return answer;
}