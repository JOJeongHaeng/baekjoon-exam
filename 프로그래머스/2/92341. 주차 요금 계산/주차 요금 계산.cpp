#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> m;
    map<string, int> total;
    for(string record : records)
    {
        if(record[11] == 'I')
        {
            int tmp = stoi(record.substr(0, 2)) * 60 + stoi(record.substr(3, 2));
            m[record.substr(6, 4)] = tmp;
        }
        else
        {
            int tmp = stoi(record.substr(0, 2)) * 60 + stoi(record.substr(3, 2));
            
            total[record.substr(6, 4)] += tmp - m[record.substr(6, 4)];
            m[record.substr(6, 4)] = -1;
        }
    }
    int limit = 23 * 60 + 59;
    for(auto iter : m)
    {
        if(iter.second != -1)
        {
            total[iter.first] += limit - m[iter.first];
        }
    }
    for(auto iter : total)
    {
        if(iter.second <= fees[0]) 
        {
            answer.push_back(fees[1]);
            continue;
        }
        int extra = (iter.second - fees[0])%fees[2] == 0 ? (iter.second - fees[0])/fees[2] : (iter.second - fees[0])/fees[2] + 1;
        int tmp = fees[1] + extra * fees[3];
        answer.push_back(tmp);
    }
    return answer;
}