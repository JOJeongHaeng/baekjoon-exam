#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int money = 0;
    sort(d.begin(), d.end());
    while(budget > money)
    {
        if(d.size() == answer) return d.size();
        if(money+d[answer] <= budget)
        {
            money+=d[answer];
            answer++;
        }
        else break;
    }
    return answer;
}