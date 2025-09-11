#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    for(int i = 0; i<nums.size()-2; i++)
    {
        for(int j = i+1; j<nums.size()-1; j++)
        {
            for(int k = j+1; k<nums.size(); k++)
            {
                int sum = nums[i]+nums[j]+nums[k];
                int tmp = 0;
                for(int x = 2; x*x <= sum; x++)
                {
                    if(sum%x == 0) tmp++;
                }
                if(tmp == 0) answer++;
            }
        }
    }

    return answer;
}