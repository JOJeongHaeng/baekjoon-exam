#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    int x=0;
    int num=0;
    string tmp = "";
    for(char ch : polynomial){
        if(ch == 'x') {
            if(tmp.size() != 0) x += stoi(tmp);
            else x++;
            tmp = "";
        }
        else if(ch == ' ') {
            if(tmp.size() != 0) {
                num += stoi(tmp);
                tmp = "";
            }
        }
        else if(ch != '+') tmp+= ch;
    }
    if(tmp.size() != 0) num += stoi(tmp);
    
    string answer;
    if(x == 1){
        if(num != 0) answer = "x + " + to_string(num);
        else answer = "x";
    }
    else if(x != 0 && num != 0) answer = to_string(x) + "x + " + to_string(num);
    else if (x == 0) answer = to_string(num);
    else answer = to_string(x) + "x";
    return answer;
}