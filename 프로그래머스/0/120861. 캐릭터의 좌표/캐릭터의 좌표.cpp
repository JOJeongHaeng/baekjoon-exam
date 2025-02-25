#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer = {0, 0};
    for(string key : keyinput){
        if(key == "left"){
            if(answer[0] != -(board[0]/2)) answer[0]--;
        }
        else if(key == "right"){
            if(answer[0] != board[0]/2) answer[0]++;
        }
        else if(key == "up"){
            if(answer[1] != board[1]/2) answer[1]++;
        }
        else if(key == "down"){
            if(answer[1] != -(board[1]/2)) answer[1]--;
        }
    }
    return answer;
}