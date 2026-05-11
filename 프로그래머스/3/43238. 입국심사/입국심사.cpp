#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long mn = 1;
    long long mx = (long long) times.back() * n;
    
    while(mx >= mn)
    {
        long long avg = (mx + mn) / 2;
        long long tmp = 0;
        for(int i = 0; i < times.size(); i++) tmp += (avg / (long long) times[i]);
        
        if(tmp < n)
        {
            mn = avg + 1;
        }
        else
        {
            mx = avg - 1;
            answer = avg;
        }
    }
    
    return answer;
}