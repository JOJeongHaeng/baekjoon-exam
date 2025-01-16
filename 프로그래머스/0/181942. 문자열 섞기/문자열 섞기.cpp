#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    int i = 0;
    while ( i < str1.size())
    {
        answer = answer + str1[i] + str2[i];
        i++;
    }
    return answer;
}