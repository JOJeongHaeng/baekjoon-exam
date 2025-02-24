#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int cnt = 0;
    for(string str1 : dic){
        for(string str2 : spell){
            if(str1.find(str2) != string::npos) cnt++;
            else {
                cnt = 0;
                break;
            }
        }
        if(cnt == spell.size()) return 1;
        else cnt = 0;
    }
    return 2;
}