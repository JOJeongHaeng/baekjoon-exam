#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int tmp = 0;
    string stmp;
    for(char c : s){
        if(c == ' '){
            if(stmp.size() != 0) {
                answer += stoi(stmp);
                tmp = stoi(stmp);
                stmp = "";
            }
        }
        else if(c == 'Z'){
            answer -= tmp;
            stmp = "";
        }
        else{
            stmp+=c;
        }
    }
    if(stmp.size() != 0) answer += stoi(stmp);
    return answer;
}