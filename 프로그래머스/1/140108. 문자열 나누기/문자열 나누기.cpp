#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char tmp = s[0];
    int same = 0;
    int dif = 0;
    for(int i=0; i<s.size(); i++){
        if(tmp == s[i]) same++;
        else dif++;
        if(same == dif){
            answer++;
            same = 0;
            dif = 0;
            if(i+1 != s.size()) tmp = s[i+1];
        }
    }
    if(same != dif) answer++;
    return answer;
}