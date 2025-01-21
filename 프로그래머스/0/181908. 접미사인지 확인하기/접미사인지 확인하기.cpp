#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    vector<string> str;
    for(int i=1; i<=my_string.size(); i++){
        str.push_back(my_string.substr(my_string.size()-i));
    }
    return find(str.begin(), str.end(), is_suffix) == str.end() ? 0:1;
}