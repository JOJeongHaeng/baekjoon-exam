#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<int> result;
    for(vector<int> tmp : score){
        answer.push_back(tmp[0]+tmp[1]);
        result.push_back(0);
    }
    
    int count = 1;

    for(int i=0; i<answer.size(); i++){
        int tmp = 0;
        int max = answer[0];
        for(int j=0; j<answer.size(); j++){
            if(answer[j] > max) max = answer[j];
        }
        for(int j=0; j<answer.size(); j++){
            if(answer[j] == max){
                result[j] = count;
                tmp++;
                answer[j] = -1;
            }
        }
        count+=tmp;
        if(tmp != 1) i+=tmp-1;
    }
    return result;
}