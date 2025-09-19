#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<vector<int>> vec(N+2, vector<int>(2, 0));
    for (int stage : stages)
    {
        for(int i = 1; i<=stage; i++)
        {
            vec[i][0]++;
        }
        if(stage <= N) vec[stage][1]++;
    }
    vector<float> tmp;
    for(int i = 1; i<=N; i++) 
    {
        if(vec[i][0]) tmp.push_back(float(vec[i][1])/float(vec[i][0]));
        else tmp.push_back(0);
    }
    
    map<int, float> m;
    for(int j = 0; j<tmp.size(); j++) m[j+1] = tmp[j];
    
    sort(tmp.begin(), tmp.end(), greater<float>());
    
    vector<int> answer;
    for(auto fail : tmp)
    {
        for(auto& iter : m)
        {
            if(iter.second == fail) 
            {
                answer.push_back(iter.first);
                iter.second = -1;
                break;
            }
        }
    }
    return answer;
}