#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> v;
    unordered_map<string, string> um;
    for(string str : record)
    {
        string tmp;
        stringstream ss(str);
        vector<string> vstr;
        while(ss >> tmp)
        {
            vstr.push_back(tmp);
        }
        v.push_back(vstr);
        if(!(vstr[0] == "Leave")) um[vstr[1]] = vstr[2];
    }
    
    for(auto vec : v)
    {
        if(vec[0] == "Enter")
        {
            string stmp = um[vec[1]] + "님이 들어왔습니다.";
            answer.push_back(stmp);
        }
        else if(vec[0] == "Leave")
        {
            string stmp = um[vec[1]] + "님이 나갔습니다.";
            answer.push_back(stmp);
        }
    }
    return answer;
}