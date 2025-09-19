#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string tmp;
    vector<int> score;
    int idx = 0;
    for(char c : dartResult)
    {
        if(isdigit(c)) tmp+=c;
        else if(isupper(c))
        {
            if(c == 'S') score.push_back(stoi(tmp));
            else if(c == 'D') score.push_back(pow(stoi(tmp), 2));
            else if(c == 'T') score.push_back(pow(stoi(tmp), 3));
            tmp.clear();
            idx++;
        }
        else if( c == '*')
        {
            if(idx == 1) score[0]*=2;
            else 
            {
                score[idx-2]*=2;
                score[idx-1]*=2;
            }
        }
        else
        {
            score[idx-1] *= -1;
        }
    }
    for(int sc : score) answer+=sc;
    return answer;
}