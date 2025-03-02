#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    for(string str : strlist){
        int count = 0;
        for(char c : str){
            count++;
        }
        answer.push_back(count);
    }
    return answer;
}