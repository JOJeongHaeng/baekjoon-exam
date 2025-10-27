#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    vector<string> v1;
    vector<string> v2;
    string tmp = "";
    
    for(char c : str1)
    {
        if(isalpha(c))
        {
            if(islower(c)) c = toupper(c);
            tmp+=c;
        }
        else
        {
            tmp.clear();
        }
        if(tmp.size() == 2)
        {
            v1.push_back(tmp);
            tmp.erase(0, 1);
        }
    }
    tmp.clear();
    for(char c : str2)
    {
        if(isalpha(c))
        {
            if(islower(c)) c = toupper(c);
            tmp+=c;
        }
        else
        {
            tmp.clear();
        }
        if(tmp.size() == 2)
        {
            v2.push_back(tmp);
            tmp.erase(0, 1);
        }
    }
    
    if(v1.size()+v2.size() == 0)
    {
        return 65536;
    }
    
    // 교집합 먼저
    vector<string> interV;
    for(int i = 0; i < v1.size(); i++)
    {
        if(find(v2.begin(), v2.end(), v1[i]) != v2.end())
        {
            interV.push_back(v1[i]);
            v2.erase(find(v2.begin(), v2.end(), v1[i]));
        }
    }
    
    for(int i = 0; i < interV.size(); i++)
    {
        v1.erase(find(v2.begin(), v2.end(), interV[i]));
    }
    
    float J = (float)interV.size()/((float)v1.size()+(float)v2.size()+(float)interV.size());
    return  J* 65536;
}