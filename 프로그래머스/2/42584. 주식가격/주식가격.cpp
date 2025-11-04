#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i =0; i<prices.size()-1; i++)
    {
        int tmp = 1;
        bool check = false;
        for(int j = i+1; j<prices.size(); j++)
        {
            if(prices[i] <= prices[j]) tmp++;
            else
            {
                check = true;
                answer.push_back(tmp);
                break;
            }
        }
        if(!check) answer.push_back(--tmp);
    }
    answer.push_back(0);
    return answer;
}