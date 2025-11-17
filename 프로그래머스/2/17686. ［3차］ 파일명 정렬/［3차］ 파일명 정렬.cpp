#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string TOLOWER(const string& str)
{
    string l_str = str;
    transform(l_str.begin(), l_str.end(), l_str.begin(), ::tolower);
    return l_str;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> v;
    for(int i = 0; i<files.size(); i++)
    {
        string head = "";
        string number = "";
        int idx = 0;
        int len = files.size();
        
        while(idx < len && !isdigit(files[i][idx]))
        {
            head += files[i][idx++];
        }
        
        while(idx < len && isdigit(files[i][idx]) && number.size() < 5)
        {
            number+=files[i][idx++];
        }
        
        v.push_back({head, number, files[i].substr(idx)});
    }
    stable_sort(v.begin(), v.end(), [](const vector<string> &a, const vector<string> &b)
    {
        if(TOLOWER(a[0]) == TOLOWER(b[0]))
        {
            return stoi(a[1]) < stoi(b[1]);
        }
        return TOLOWER(a[0]) < TOLOWER(b[0]);
    });
    for(auto vec : v)
    {
        string tmp;
        for(auto str : vec)
        {
            tmp+=str;
        }
        answer.push_back(tmp);
    }
    return answer;
}