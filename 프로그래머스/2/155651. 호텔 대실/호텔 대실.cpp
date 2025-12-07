#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int timetoint(string str)
{
    stringstream ss(str);
    string tmp;
    vector<string> v;
    while(getline(ss, tmp, ':'))
    {
        v.push_back(tmp);
    }
    return (stoi(v[0]) * 60) + stoi(v[1]);
}

int solution(vector<vector<string>> book_time) {
    vector<vector<int>> times;
    for(vector<string> v : book_time)
    {
        times.push_back({timetoint(v[0]), (timetoint(v[1]) + 10)});
    }
    
    sort(times.begin(), times.end());
    vector<vector<int>> timetable;
    int answer = 1;
    timetable.push_back(times[0]);
        
    for(int i = 1; i<times.size(); i++)
    {
        bool check = true;
        for(int j = 0; j<timetable.size(); j++)
        {
            if(times[i][0] >= timetable[j][1])
            {
                check = false;
                timetable.erase(timetable.begin()+j);
                break;
            }
        }
        if(check) answer++;
        timetable.push_back(times[i]);
    }
    
    return answer;
}