#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    for (int i=0; i<arr.size(); i++){
        if(flag[i]==true){
            for (int n = 0; n<arr[i]*2; n++) answer.push_back(arr[i]);
        }
        else{
            for (int n = 0; n<arr[i]; n++) answer.erase(answer.end()-1);
        }
    }
    return answer;
}