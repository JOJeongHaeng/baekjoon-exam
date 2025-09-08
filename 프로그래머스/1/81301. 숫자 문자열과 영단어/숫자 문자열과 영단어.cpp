#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    map<string, string> m;
    m["zero"] = "0";
    m["one"] = "1";
    m["two"] = "2";
    m["three"] = "3";
    m["four"] = "4";
    m["five"] = "5";
    m["six"] = "6";
    m["seven"] = "7";
    m["eight"] = "8";
    m["nine"] = "9";
    for(auto iter : m)
    {
        while(s.find(iter.first) != string::npos)
        {
            s.replace(s.find(iter.first), iter.first.length(), iter.second);
        }
    }
    answer = stoi(s);
    return answer;
}