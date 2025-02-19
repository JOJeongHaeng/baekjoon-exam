#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    for(vector<string> tmp : db){
        if(tmp[0] == id_pw[0]){
            if(tmp[1] == id_pw[1]) return "login";
            else answer = "wrong pw";
        }
    }
    if(answer != "wrong pw") answer = "fail";
    return answer;
}