#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int s_op = stoi(op_start.substr(0, 2))*60 + stoi(op_start.substr(3, 5));
    int e_op = stoi(op_end.substr(0, 2))*60 + stoi(op_end.substr(3, 5));
    int t_pos = stoi(pos.substr(0, 2))*60 + stoi(pos.substr(3, 5));
    int v_len = stoi(video_len.substr(0, 2))*60 + stoi(video_len.substr(3, 5));
    
    for(string command : commands){
        if(s_op<=t_pos && t_pos<=e_op) t_pos = e_op;
        if(command == "next"){
            t_pos+=10;
            if(t_pos > v_len) t_pos = v_len;
        }
        else if(command == "prev"){
            t_pos-=10;
            if(t_pos < 0) t_pos = 0;
        }
    }
    if(s_op<=t_pos && t_pos<=e_op) t_pos = e_op;
    
    int mm = t_pos/60;
    int ss = t_pos%60;
    if(mm == 0) answer+="00";
    else if(mm < 10) answer+="0"+to_string(mm);
    else answer+=to_string(mm);
    
    answer+=":";
    
    if(ss == 0) answer+="00";
    else if(ss < 10) answer+="0"+to_string(ss);
    else answer+=to_string(ss);
    return answer;
}