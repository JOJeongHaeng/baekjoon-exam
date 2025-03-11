#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(char ch : s){
        int count = index;
        while(count > 0){
            ch++;
            if(ch > 'z') ch='a';
            if(skip.find(ch) == string::npos) count--;
        }
        answer+=ch;
    }
    return answer;
}