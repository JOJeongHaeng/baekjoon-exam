#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string A, string B) {
    int answer = 0;
    if (A==B) return answer;
    for(int i=0; i<A.size()-1; i++){
        string tmp="";
        tmp = tmp + A.substr(A.size()-1, 1) + A.substr(0, A.size()-1);
        answer++;
        if (tmp==B) return answer;
        else A=tmp;
    }
    return -1;
}