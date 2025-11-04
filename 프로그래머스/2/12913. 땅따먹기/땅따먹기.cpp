#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    vector<int> prev = land[0];
    for(int i = 1; i<land.size(); i++)
    {
        vector<int> current = land[i];
        for(int j = 0; j<4; j++)
        {
            int Max = 0;
            for(int k = 0; k<4; k++)
            {
                if(j!=k) Max = Max > current[j] + prev[k] ? Max : current[j] + prev[k];
            }
            current[j] = Max;
        }
        prev = current;
    }

    return *max_element(prev.begin(), prev.end());
}