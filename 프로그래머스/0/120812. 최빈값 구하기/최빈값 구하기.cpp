#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) {
    map<int, int> m;
    for(int i: array) m[i]++;
    int max = m.begin()-> second;
    int answer = m.begin()->first;
    for(auto iter = m.begin(); iter != m.end(); iter++){
        if(iter->second > max){
            max = iter->second;
            answer = iter->first;
        }
    }
    int count = 0;
    for(auto iter = m.begin(); iter != m.end(); iter++){
        if(iter->second == max) count++;
    }
    count != 1 ? answer = -1 : answer;
    return answer;
}