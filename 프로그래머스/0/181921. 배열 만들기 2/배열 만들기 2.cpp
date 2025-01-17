#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for (int i = ((l/5)*5); i <= r; i+=5){
        string str = to_string(i);
        int count = 0;
        for (char c:str){
            if (c!='5' && c!='0') 
                break;
            else{
                count++;
            }
        }
        if (count == str.size()){
            answer.push_back(i);
        }
    }
    if(answer.empty()) answer.push_back(-1);
    return answer;
}