#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(string str:quiz){
        vector<string> tmpV;
        string tmp="";
        for(char c : str){
            if (c!=' ') tmp+=c;
            else {
                tmpV.push_back(tmp);
                tmp = "";
            }
        }
        tmpV.push_back(tmp);
        int first = stoi(tmpV[0]);
        int second = stoi(tmpV[2]);
        int third = stoi(tmpV.back());
        if (tmpV[1] == "+"){
            if (first + second == third) answer.push_back("O");
            else answer.push_back("X");
            }
        else {
            if (first - second == third) answer.push_back("O");
            else answer.push_back("X");
            }
    }
    return answer;
}