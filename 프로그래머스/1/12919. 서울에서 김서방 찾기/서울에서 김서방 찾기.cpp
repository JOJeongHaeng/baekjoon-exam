#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer;
    int x = 0;
    for(string str : seoul)
    {
        if(str == "Kim") answer = "김서방은 " + to_string(x) + "에 있다";
        else x++;
    }
    return answer;
}