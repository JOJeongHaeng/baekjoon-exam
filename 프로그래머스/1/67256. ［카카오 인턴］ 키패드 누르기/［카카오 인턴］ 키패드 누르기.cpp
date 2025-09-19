#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<int> LH = {0, 3};
    vector<int> RH = {2, 3};
    for(int num : numbers)
    {
        if((num-1)%3 == 0) 
        {
            answer+="L";
            LH[0] = 0;
            LH[1] = (num-1)/3;
        }
        else if((num-1)%3 == 2) 
        {
            answer+="R";
            RH[0] = 2;
            RH[1] = (num-1)/3;
        }
        else
        {
            vector<int> now;
            if(num != 0) now = { (num-1)%3, (num-1)/3 };
            else now = { 1, 3 };
            int DisL = abs(now[0]-LH[0])+abs(now[1]-LH[1]);
            int DisR = abs(now[0]-RH[0])+abs(now[1]-RH[1]);
            if(DisL < DisR)
            {
                answer+="L";
                LH[0] = now[0];
                LH[1] = now[1];
            }
            else if(DisR < DisL)
            {
                answer+="R";
                RH[0] = now[0];
                RH[1] = now[1];
            }
            else
            {
                if(hand == "right")
                {
                    answer+="R";
                    RH[0] = now[0];
                    RH[1] = now[1];
                }
                else
                {
                    answer+="L";
                    LH[0] = now[0];
                    LH[1] = now[1];
                }
            }
        }
    }
    return answer;
}