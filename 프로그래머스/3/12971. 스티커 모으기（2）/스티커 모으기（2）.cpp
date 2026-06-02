#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int len = sticker.size();
    if(len == 1) return sticker[0];
    int dp1[len];
    int dp2[len];
    
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    
    dp1[0] = sticker[0];
    dp1[1] = sticker[0];
    dp2[1] = sticker[1];
    
    for(int i = 2; i<len - 1; i++)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }
    dp2[len - 1] = max(dp2[len - 2], dp2[len - 3] + sticker[len - 1]);
    
    answer = max(dp1[len - 2], dp2[len -1]);
    
    return answer;
}