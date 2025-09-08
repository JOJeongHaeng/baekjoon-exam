#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int zero = 0;
    int current = 0;
    int best = 0;
    int worst = 0;
    
    for(int lotto : lottos)
    {
        if (lotto == 0) zero++;
        else if (find(win_nums.begin(), win_nums.end(), lotto) != win_nums.end()) current++;
    }
    best = 7 - (current+zero);
    worst = 7 - current;
    if(best > 6) best = 6;
    if(worst > 6) worst = 6;
    answer.push_back(best);
    answer.push_back(worst);
    return answer;
}