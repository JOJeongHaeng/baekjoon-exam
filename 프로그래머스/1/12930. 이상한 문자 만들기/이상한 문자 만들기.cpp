#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != ' ') tmp+=s[i];
        else
        {
            if(tmp.length()!=0)
            {
                for(int j = 0; j<tmp.size(); j++)
                {
                    if(j%2==0) tmp[j] = toupper(tmp[j]);
                    else tmp[j] = tolower(tmp[j]);
                }
                answer+=tmp;
                tmp.clear();
            }
            answer+=" ";
        }
    }
    if(tmp.length()!=0)
    {
        for(int k = 0; k<tmp.size(); k++)
        {
            if(k%2==0) tmp[k] = toupper(tmp[k]);
            else tmp[k] = tolower(tmp[k]);
        }
        answer+=tmp;
    }
    return answer;
}