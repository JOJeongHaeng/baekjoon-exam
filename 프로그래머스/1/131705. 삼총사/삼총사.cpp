#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for(int i = 0; i < number.size(); i++)
    {
        for(int j = 1; j < number.size(); j++)
        {
            for(int k =2; k < number.size(); k++)
            {
                if(i<j && j<k)
                {
                    if(number[i]+number[j]+number[k] == 0) answer++;
                }
            }
        }
    }
    return answer;
}