#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> words = {"aya", "ye", "woo", "ma"};
    for (string& str : babbling){
        string tmp;
        for (string word : words){
            if (str.find(word) != string::npos){
                str.replace(str.find(word), word.size(), "*");
                tmp+="*";
            }
        }
        if(str==tmp) answer++;
    }
    return answer;
}