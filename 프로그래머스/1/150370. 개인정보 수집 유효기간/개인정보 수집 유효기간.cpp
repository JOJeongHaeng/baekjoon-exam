#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int idx = 1;
    for(string privacy : privacies){
        int today_d = stoi(today.substr(2, 4))*12*28 + stoi(today.substr(5, 7))*28 + stoi(today.substr(8, 10));
        int start_d = stoi(privacy.substr(2, 4))*12*28 + stoi(privacy.substr(5, 7))*28 + stoi(privacy.substr(8, 10));
        
        int dif = today_d - start_d;
        char type = privacy.back();
        int check;
        
        for(string term : terms){
            if(term[0] == type) {
                if(term.size() == 3) check = term[2] - '0';
                else check = stoi(term.substr(2, 4));
            }
        }
        if(dif >= check * 28) answer.push_back(idx);
        idx++;
    }
    return answer;
}