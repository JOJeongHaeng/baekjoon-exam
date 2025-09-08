#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> id_idx;
    for (int i = 0; i<id_list.size(); i++) 
    {
        id_idx[id_list[i]] = i;
    }
    map<string, set<string>> report_id;
    
    for(string str : report)
    {
        stringstream ss(str);
        string from, to;
        ss >> from >> to;
        
        report_id[to].insert(from);
    }
    for(auto iter : report_id)
    {
        if(iter.second.size() >= k)
        {
            for(string name : iter.second)
            {
                answer[id_idx[name]]++;
            }
        }
    }
    
    return answer;
}