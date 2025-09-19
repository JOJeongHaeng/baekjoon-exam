#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer;
    for(char& c : new_id)
    {
        if (islower(c)) answer += c;
        else if (isupper(c)) answer += tolower(c);
        else if (isdigit(c)) answer += c;
        else if (c == '-') answer += c;
        else if (c == '_') answer += c;
        else if (c == '.' && answer.back() != '.')
        {
            if(!answer.empty()) answer += c;
        }
    }
    if(answer.length() >= 16) answer = answer.substr(0, 15);
    else if(answer.empty()) answer+='a';
    if(answer.back() == '.') answer.erase(answer.end()-1);
    if(answer.length() <= 2)
    {
        while(answer.length() != 3)
        {
            answer+=answer.back();
        }
    }
    return answer;
}