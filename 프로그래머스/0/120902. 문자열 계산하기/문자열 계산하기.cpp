#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    vector<string> tmpV;
    string tmp;
    for(int i=0; i<my_string.size(); i++){
        if(my_string[i] != ' '){
            tmp+=my_string[i];
        }
        else {
            tmpV.push_back(tmp);
            tmp="";
        }
    }
    tmpV.push_back(tmp);
    for(int i=0; i<tmpV.size(); i++){
        if (tmpV[i] == "-"){
            tmpV[i+1] = "-"+tmpV[i+1];
        }
        else if (tmpV[i] == "+");
        else{
            answer+=stoi(tmpV[i]);
        }
    }
    return answer;
}