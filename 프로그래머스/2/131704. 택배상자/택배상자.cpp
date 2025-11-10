#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int num = 1;
    int Size = order.size();
    int idx = 0;
    
    stack<int> s;
    
    while(num <= Size+1 && idx < Size)
    {
        if(num == order[idx])
        {
            answer++;
            idx++;
            num++;
        }
        else if(!s.empty() && s.top() == order[idx])
        {
            answer++;
            s.pop();
            idx++;
        }
        else
        {
            s.push(num);
            num++;
        }
    }
    return answer;
}