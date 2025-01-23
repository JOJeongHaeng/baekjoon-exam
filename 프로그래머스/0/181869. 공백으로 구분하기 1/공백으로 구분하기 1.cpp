#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    while(true){
        if(my_string.find(" ")!=string::npos){
            answer.push_back(my_string.substr(0, my_string.find(" ")));
            my_string = my_string.substr(my_string.find(" ")+1, -1);
        }
        else {
            answer.push_back(my_string);
            break;
        }
    }
    return answer;
}