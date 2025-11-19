#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(int& number : numbers)
    {
        v.push_back(to_string(number));
    }
    
    sort(v.begin(), v.end(), [](string const& a, string const& b)
         {
             return a+b>b+a;
         });
    
    for(string str : v)
    {
        answer += str;
    }
    return answer[0] == '0' ? "0" : answer;
}