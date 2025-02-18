#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> m;
    for(char ch : s){
        m[ch]++;
    }
    for(auto i : m){
        if(i.second == 1){
            answer+=i.first;
        }
    }
    return answer;
}