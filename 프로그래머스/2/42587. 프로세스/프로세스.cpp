#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    while(true)
    {
        bool check = true;
        if(location < 0) location = priorities.size()-1;
        int tmp = priorities.front();
        priorities.erase(priorities.begin());
        for(int i : priorities)
        {
            if(tmp < i) 
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            if(location == 0) return answer;
            else answer++;
        }
        else
        {
            priorities.push_back(tmp);
        }
        if(--location < 0) location = priorities.size()-1;
    }
    return answer;
}