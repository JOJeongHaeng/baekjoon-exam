#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for(int i = 0; i < 52; i++) answer.push_back(0);
    for (char c : my_string){
        if (isupper(c)) answer[(int)c-65]+=1;
        else answer[(int)c-71]+=1;
    }
    return answer;
}