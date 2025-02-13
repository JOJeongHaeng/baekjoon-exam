#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    for(int i=-(num/2); i<total/2; i++){
        int tmp=0;
        for(int j=0; j<num; j++){
            tmp= tmp+i+j;
            answer.push_back(i+j);
        }
        if(total == tmp) return answer;
        else answer.erase(answer.begin(), answer.end());
    }
}