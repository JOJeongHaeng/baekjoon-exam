#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> iv;
    for (int i = 0; i<arr.size(); i++){
        if (arr[i] == 2){
            iv.push_back(i);
        }
    }
    if (iv.size() != 0){
        return vector<int>(arr.begin()+iv.front(), arr.begin()+iv.back()+1);
    }
    vector<int> answer;
    answer.push_back(-1);
    return  answer;
}