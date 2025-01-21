#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for (string int_s : intStrs){
        int i = stoi(int_s.substr(s, l));
        if (i > k){
            answer.push_back(i);
        }
    }
    return answer;
}