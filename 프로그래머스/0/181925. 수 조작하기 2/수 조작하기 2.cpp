#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    int num = numLog[0];
    numLog.erase(numLog.begin());
    for (int i : numLog){
        if (i-num == 1){
            num = i;
            answer += "w";
        }
        else if (i-num == -1){
            num = i;
            answer += "s";
        }
        else if (i-num == 10){
            num = i;
            answer += "d";
        }
        else if (i-num == -10){
            num = i;
            answer += "a";
        }
    }
    return answer;
}