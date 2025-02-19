#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(char ch : my_string){
        if(isupper(ch) != 0) answer.push_back(tolower(ch));
        else answer.push_back(toupper(ch));
    }
    return answer;
}