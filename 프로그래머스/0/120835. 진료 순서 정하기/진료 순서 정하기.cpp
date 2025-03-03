#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer(emergency.size());
    int count = 1;
    for(int i=0; i<emergency.size(); i++){
        int mn = emergency[0];
        int idx = 0;
        for(int j=0; j<emergency.size(); j++){
            if(mn < emergency[j]){
                mn = emergency[j];
                idx = j;
            }
        }
        answer[idx] = count++;
        emergency[idx] = 0;
    }
    return answer;
}