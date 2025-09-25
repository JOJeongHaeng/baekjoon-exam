#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    
    map<int, int> m;
    for(int size : tangerine)
    {
        m[size]++;
    }
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    int remove = tangerine.size() - k;
    
    int answer = v.size();
    for(int i = 0; i<v.size(); i++)
    {
        if(v[i].second > remove) break;
        else
        {
            remove-=v[i].second;
            answer--;
        }
    }
    return answer;
}