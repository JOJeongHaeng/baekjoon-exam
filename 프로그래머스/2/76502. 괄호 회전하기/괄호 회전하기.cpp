#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i = 0; i<s.size()-1; i++)
    {
        stack<char> st;
        
        for(char c : s)
        {
            if(c == '[' || c == '(' || c == '{')
            {
                st.push(c);
            }
            else if(c == ']' || c == ')' || c == '}')
            {
                if(st.empty()) 
                {
                    st.push('*');
                    break;
                }
                else
                {
                    char tmp = st.top();
                    if(c == ']' && tmp != '[') 
                    {
                        st.push('*');
                        break;
                    }
                    else if(c == '}' && tmp != '{') 
                    {
                        st.push('*');
                        break;
                    }
                    else if(c == ')' && tmp != '(')
                    {
                        st.push('*');
                        break;
                    }
                    st.pop();
                }
            }
        }
        if(st.empty()) answer++;
        char tmp = s[0];
        s = s.substr(1, s.size()-1) + tmp;
    }
    return answer;
}