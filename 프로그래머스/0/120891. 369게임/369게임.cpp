#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    string str = to_string(order);
    for(char ch : str){
        if(ch == '3') answer++;
        else if(ch == '6') answer++;
        else if(ch == '9') answer++;
    }
    return answer;
}