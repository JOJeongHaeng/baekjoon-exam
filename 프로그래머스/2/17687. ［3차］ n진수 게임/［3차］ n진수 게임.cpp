#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0;
    string total;
    int idx = p;
    while(answer.size() != t)
    {
        string tmp;
        int nownum = num;
        do
        {
            int remain = nownum%n;
            char alpha;
            if(10 <= remain)
            {
                alpha = remain+55;
                tmp = alpha + tmp;
            }
            else
            {
                tmp = to_string(remain) + tmp;
            }
            nownum/=n;
        }
        while(nownum > 0);
        
        total += tmp;
        while(total.size() >= idx && answer.size() != t)
        {
            answer+=total[idx-1];
            idx+=m;
        }
        num++;
    }
    return answer;
}