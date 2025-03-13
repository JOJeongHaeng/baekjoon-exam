#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> u_m;
    for(int i=0; i<s.size(); i++){
        if(u_m.find(s[i]) == u_m.end()){
            answer.push_back(-1);
            u_m[s[i]] = i;
        }
        else{
            answer.push_back(i-u_m[s[i]]);
            u_m[s[i]] = i;
        }
    }
    return answer;
}