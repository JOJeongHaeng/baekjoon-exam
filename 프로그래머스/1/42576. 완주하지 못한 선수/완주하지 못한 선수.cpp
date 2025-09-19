#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    for(string name : participant) m[name]++;
    for(string clear : completion) m[clear]--;
    for(auto iter : m) 
    {
        if(iter.second != 0) return iter.first;
    }
}