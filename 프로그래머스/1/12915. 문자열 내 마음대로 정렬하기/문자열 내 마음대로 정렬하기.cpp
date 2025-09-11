#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    for(string& str : strings) str = str[n]+str;
    sort(strings.begin(), strings.end());
    for(string& str : strings) str.erase(str.begin());
    return strings;
}