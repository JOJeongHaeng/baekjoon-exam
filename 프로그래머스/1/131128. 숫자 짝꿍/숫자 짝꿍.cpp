#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> vx(10, 0);
    vector<int> vy(10, 0);
    bool check_no = true;
    
    for(int i = 9; i>=0; i--)
    {
        char inttoc = '0'+i;
        for(char c : X)
        {
            if(c == inttoc) vx[i]++;
        }
        for(char c : Y)
        {
            if(c == inttoc) vy[i]++;
        }
    }
    
    for(int i = 9; i>=0; i--)
    {
        if(vx[i] != 0 && vy[i] != 0)
        {
            if(i==0 && answer.size() == 0) return "0";
            char c = '0'+i;
            int comp = vx[i] < vy[i] ? vx[i] : vy[i];
            for(int j = 0; j<  comp; j++) answer+=c;
            if(check_no) check_no=false; 
        }
    }
    return check_no ? "-1" : answer;
}