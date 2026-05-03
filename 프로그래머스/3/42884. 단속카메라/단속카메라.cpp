#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& a, vector<int>& b)
{
    if(a[0] <= b[0] && a[1] >= b[0]) return true;
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    vector<vector<int>> v;
    
    sort(routes.begin(), routes.end());
    v.push_back(routes[0]);
    for(int i = 1; i<routes.size(); i++)
    {
        bool tmp = false;
        for(int j = 0; j<v.size(); j++)
        {
            if(check(v[j], routes[i])) 
            {
                tmp = true;
                v[j] = {routes[i][0], min(routes[i][1], v[j][1])};
                break;
            }
        }
        if(!tmp)
        {
            v.push_back(routes[i]);
            answer++;
        }
    }
    return answer;
}