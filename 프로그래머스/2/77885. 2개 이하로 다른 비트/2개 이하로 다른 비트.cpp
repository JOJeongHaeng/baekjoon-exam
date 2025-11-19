#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long number : numbers)
    {
        int cnt = 0;
        while(1)
        {
            if((number & 1LL<<cnt) == 0) break;
            cnt++;
        }
        if(cnt)
        {
            number = number + (1LL<<cnt) - (1LL << (cnt-1));
        }
        else
        {
            number = number + (1LL<<cnt);
        }
        answer.push_back(number);
    }
    return answer;
}