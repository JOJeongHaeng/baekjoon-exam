#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool rev(int a, int b)
{
    return a>b;
}

string solution(string s) {
    string answer = "";
    vector<int> v;
    for(int i : s)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end(), rev);
    for(int i : v)
    {
        char c = i;
        answer+=c;
    }
    return answer;
}