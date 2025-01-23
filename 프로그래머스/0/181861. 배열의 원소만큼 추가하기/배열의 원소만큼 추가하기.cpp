#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for (int i : arr){
        for(int n=0; n<i; n++) answer.push_back(i);
    }
    return answer;
}