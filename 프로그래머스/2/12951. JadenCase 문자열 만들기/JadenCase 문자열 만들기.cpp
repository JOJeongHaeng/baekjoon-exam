#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "", tmp;
    for(int i =0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            tmp+= ' ';
            if(islower(tmp[0])) tmp[0] = toupper(tmp[0]);
            answer+=tmp;
            tmp.clear();
            continue;
        }
        else if(isupper(s[i])) tmp+=tolower(s[i]);
        else tmp+=s[i];
    }
    if(islower(tmp[0])) tmp[0] = toupper(tmp[0]);
    answer+=tmp;
    return answer;
}