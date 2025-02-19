#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
    for(char ch : before){
        if(after.find(ch)!=string::npos) after.erase(after.find(ch), 1);
        else return 0;
    }
    return 1;
}