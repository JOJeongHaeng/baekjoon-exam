#include <string>
#include <vector>
#include<map>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    map<int, int> m;
    for (string str : strArr){
        m[str.length()]++;
    }
    for (int i=0; i<m.size(); i++){
        if (answer<m[i]) answer = m[i];
    }
    return answer;
}