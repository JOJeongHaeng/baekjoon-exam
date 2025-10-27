#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> st({0});
    
    for(int i = 1; i<numbers.size(); i++)
    {
        while(!st.empty())
        {
            if(numbers[st.top()] >= numbers[i]) break;
            else
            {
                answer[st.top()] = numbers[i];
                st.pop();
            }
        }
        st.push(i);
    }
    return answer;
}