#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    for(char c : to_string(age)) answer+= c+'1';
    return answer;
}