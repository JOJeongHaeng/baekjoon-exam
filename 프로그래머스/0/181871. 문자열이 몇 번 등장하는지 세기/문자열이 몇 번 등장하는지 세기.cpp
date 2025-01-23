#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for (int i = 0; i<=myString.size()-pat.size(); i++){
        string sub = myString.substr(i, pat.size());
        if (sub == pat) answer++;
    }
    return answer;
}