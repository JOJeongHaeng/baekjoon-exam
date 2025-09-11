#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    if(s.size() != 4 && s.size() != 6) return 0;
    for(char c : s)
    {
        if(isalpha(c) != 0) return 0;
    }
    return true;
}