#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

void dfs(string& numbers, string number, vector<bool>& v, unordered_set<int>& us)
{
    int count = 0;
    if(number != "")
    {
        int tmp = stoi(number);
        if(v[tmp]) us.insert(tmp);
    }
    
    for(int i = 0; i<numbers.size(); i++)
    {
        string now = number+numbers[i];
        string next = "";
        if(i!=0) next += numbers.substr(0, i);
        if(i!=numbers.size()-1) next += numbers.substr(i+1, numbers.size()-i-1);
        
        dfs(next, now, v, us);
    }
    return;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), [](const char& a, const char& b){ return a > b; });
    int number = stoi(numbers);
    unordered_set<int> us;
    vector<bool> v(number, true);
    
    v[0] = false; v[1] = false;
    for(int i = 2; i*i <= number; i++)
    {
        int j = i*i;
        while(j <= number)
        {
            v[j] = false;
            j+=i;
        }
    }
    
    dfs(numbers, "", v, us);
    answer = us.size();
    return answer;
}