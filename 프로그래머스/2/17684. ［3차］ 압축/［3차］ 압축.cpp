#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) 
{
    vector<int> answer;
    map<string, int> m;
    int i = 0;
    for(; i<=25; i++)
    {
        m[string(1, 'A'+i)] = i+1;
    }
    
    string tmp;
    string exit;
    for(int j =0; j<msg.size();j++)
    {
        tmp+=msg[j];
        if(m[tmp] != 0)
        {
            exit = tmp;
        }
        else
        {
            answer.push_back(m[exit]);
            m[tmp] = ++i;
            tmp = "";
            j--;
        }
    }
    answer.push_back(m[exit]);
    
    return answer;
}