#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string tmp;
    vector<int> v;
    while(ss >> tmp)
    {
        v.push_back(stoi(tmp));
    }
    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    
    answer = to_string(mn) + " " + to_string(mx);
    return answer;
}