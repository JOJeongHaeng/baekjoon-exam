#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char c : s)
    {
        if(isupper(c))
        {
            c+=n;
            if(c-'A' > 25) c-=26;
            answer+=c;
        }
        else if(islower(c))
        {
            int tmp = c+n;
            if(tmp > 'z') c = tmp - 26, answer+=c;
            else answer+=char(tmp);
        }
        else answer+=c;
    }
    return answer;
}