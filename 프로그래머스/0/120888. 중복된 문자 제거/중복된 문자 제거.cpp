#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(char ch : my_string){
        if(answer.find(ch) == string::npos) answer+=ch;
    }
    return answer;
}