#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer = vector<int>(arr.begin()+intervals[0][0], arr.begin()+intervals[0][1]+1);
    vector<int> answer2 = vector<int>(arr.begin()+intervals[1][0], arr.begin()+intervals[1][1]+1);
    for (int i : answer2){
        answer.push_back(i);
    }
    return answer;
}