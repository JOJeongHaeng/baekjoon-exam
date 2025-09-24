#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int change = 0;
    int zero = 0;
    while(s != "1")
    {
        string tmp;
        for(char& c : s)
        {
            if(c == '1') tmp+='1';
            else zero++;
        }
        int num = tmp.size();
        s.clear();
        while(num != 0)
        {
            s = to_string(num%2) + s;
            num/=2;
        }
        change++;
    }
    answer = {change, zero};
    return answer;
}