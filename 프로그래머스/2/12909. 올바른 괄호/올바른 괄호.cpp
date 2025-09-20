#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int left = 0, right = 0;
    for(char c : s)
    {
        if(c == '(') left++;
        else if(c == ')') right++;
        if (left < right) return false;
    }
    if(left == right) return true; 
    return false;
}