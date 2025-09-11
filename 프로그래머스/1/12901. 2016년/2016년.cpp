#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int day = 5;
    for(int i = 1; i<a; i++)
    {
        if(i<=7)
        {
            if(i & 1) day+= 31;
            else if (i==2) day+= 29;
            else day+=30;
        }
        else
        {
            if(i & 1) day+= 30;
            else day+=31;
        }
    }
    day+=b-1;
    return week[day%7];
}