#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int tmp = 0;
    while(!progresses.empty())
    {
        if(progresses[0]<100)
        {
            if(tmp != 0)
            {
                answer.push_back(tmp);
                tmp = 0;
            }
            for(int i = 0; i<progresses.size(); i++)
            {
                progresses[i] += speeds[i];
            }
        }
        else
        {
            tmp++;
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
        }
    }
    if(tmp != 0)
    {
        answer.push_back(tmp);
        tmp = 0;
    }
    return answer;
}