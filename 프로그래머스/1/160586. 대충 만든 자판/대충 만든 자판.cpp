#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(string target : targets){
        int count = 0;
        bool flag = true;
        for(char c : target){
            vector<int> tmp;
            for(int i=0; i<keymap.size(); i++){
                for(int j=0; j<keymap[i].size(); j++){
                    if(keymap[i][j] == c) tmp.push_back(j);
                }
            }
            if(tmp.size() == 0){
                flag = false;
                break;
            }
            else{
                int min_n = tmp[0];
                for(int num : tmp) min_n = min(min_n, num);
                count+=min_n+1;
            }
        }
        if(flag == false) answer.push_back(-1);
        else answer.push_back(count);
    }
    return answer;
}