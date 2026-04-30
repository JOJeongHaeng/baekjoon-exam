#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, vector<pair<int, int>>> m;
    map<string, int> count_m;
    for(int i = 0; i < genres.size(); i++)
    {
        m[genres[i]].push_back({plays[i], i});
        count_m[genres[i]] += plays[i];
    }
    
    for(auto iter : m)
    {
        sort(m[iter.first].begin(), m[iter.first].end(), [](pair<int, int> &p1, pair<int, int> &p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        });
    }
    vector<pair<string, vector<pair<int, int>>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](pair<string, vector<pair<int, int>>>& p1, pair<string, vector<pair<int, int>>>& p2)
         {
             return p1.second.front().first >= p2.second.front().first;
         });
    
    vector<pair<string, int>> count_v(count_m.begin(), count_m.end());
    
    sort(count_v.begin(), count_v.end(), [](auto &p1, auto &p2)
         {
             return p1.second > p2.second;
         });
    
    for(auto iter : count_v)
    {
        for(auto p : v)
        {
            if(p.first == iter.first)
            {
                if(p.second.size() == 1) answer.push_back(p.second.front().second);
                else
                {
                    for(int i = 0; i<=1; i++)
                    {
                        answer.push_back(p.second[i].second);                
                    }
                }
            }
            
        }
    }
    return answer;
}