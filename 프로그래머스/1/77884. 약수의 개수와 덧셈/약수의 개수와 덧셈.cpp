#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i<= right; i++)
    {
        int count = 0;
        for(int j  = 1; j <= sqrt(i); j++)
        {
            for(int k = sqrt(i); k <= i; k++)
            {
                if(j*k == i) 
                {
                    if(j == k) count++;
                    else count+=2;
                }
            }
        }
        if(count % 2 == 0) answer+=i;
        else answer-=i;
    }
    return answer;
}