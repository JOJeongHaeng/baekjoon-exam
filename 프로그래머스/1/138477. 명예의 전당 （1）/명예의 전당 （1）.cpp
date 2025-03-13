#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> tmp;
    for(int i : score){
        tmp.push_back(i);
        sort(tmp.begin(), tmp.end(), greater<>());
        if(tmp.size() <= k) answer.push_back(tmp.back());
        else answer.push_back(tmp[k-1]);
    }
    return answer;
}