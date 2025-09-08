#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> canbabbling = {"aya", "ye", "woo", "ma"};
    for(string str : babbling)
    {
        string tmp = "";
        for(string can : canbabbling)
        {
            size_t pos = str.find(can);
            while(pos != string::npos)
            {
                str.replace(pos, can.length(), "*");
                tmp+="*";
                if(pos+1 == str.find(can)) break;
                pos = str.find(can);
            }
        }
        if(str == tmp) answer++;
    }
    return answer;
}