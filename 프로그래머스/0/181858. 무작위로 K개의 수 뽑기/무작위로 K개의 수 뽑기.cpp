#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    for (int i : arr){
        if (find(answer.begin(), answer.end(), i)==answer.end()) answer.push_back(i);
    }
    if (answer.size()<k) {
        while(answer.size()!=k){
            answer.push_back(-1);
        }
    }
    else if(answer.size()>k){
        while(answer.size()!=k){
            answer.pop_back();
        }
    }
    return answer;
}