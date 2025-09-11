#include <string>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int sum = 0;
    for(char c : s)
    {
        if(c=='p' || c=='P') sum++;
        else if(c=='y' || c=='Y') sum--;
    }
    return sum == 0;
}