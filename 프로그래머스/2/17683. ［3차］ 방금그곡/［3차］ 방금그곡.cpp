#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    unordered_map<string, int> answer;
    unordered_map<string, string> check = {{"C#", "c"}, {"D#", "d"},
                                         {"E#", "e"}, {"F#", "f"},
                                         {"G#", "g"}, {"A#", "a"}, {"B#", "b"}};
    for(string music : musicinfos)
    {
        stringstream ss(music);
        string tmp;
        vector<string> v;
        
        while(getline(ss, tmp, ','))
        {
            v.push_back(tmp);
        }
        
        string name = v[2], sheet = v[3];
        int start = stoi(v[0].substr(0, 2)) * 60 + stoi(v[0].substr(3, 2));
        int end = stoi(v[1].substr(0, 2)) * 60 + stoi(v[1].substr(3, 2));
        
        for(auto p : check)
        {
            while(m.find(p.first) != string::npos)
            {
                m.replace(m.find(p.first), 2, p.second);
            }
            while(sheet.find(p.first) != string::npos)
            {
                sheet.replace(sheet.find(p.first), 2, p.second);
            }
        }
        
        string play;
        int playtime = end-start;
        cout << playtime << endl;
        int idx = 0;
        for(int i = 0; i<playtime; i++)
        {
            idx%=sheet.size();
            play+=sheet[idx];
            idx++;
        }
        
        if(play.find(m) != string::npos)
        {
            answer[name] = end - start;
        }
    }
    if(!answer.size()) return "(None)";
    
    string name;
    int max_time = 0;
    for(auto p : answer)
    {
        if(p.second >= max_time)
        {
            max_time = p.second;
            name = p.first;
        }
    }
    return name;
}