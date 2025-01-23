#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string tmp;
    for (char c : myString){
        if (c != 'x'){
            tmp.push_back(c);
        }
        else if (tmp.size()!=0){
            answer.push_back(tmp);
            tmp.clear();
        }
    }
    if(tmp.size() !=0) answer.push_back(tmp);
    sort(answer.begin(), answer.end());
    return answer;
}