#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    string str = "";
    while(n > 0)
    {
        str = to_string(n%k) + str;
        n/=k;
    }
    stringstream ss(str);
    string tmp;
    while(getline(ss, tmp, '0'))
    {
        if(tmp.empty() || tmp == "1") continue;
        long num = stol(tmp);
        bool check = true;
        long max = sqrt(num);
        for(long i = 2; i<=max; i++)
        {
            if(num%i == 0)
            {
                check = false;
                break;
            }
        }
        if(check) answer++;
    }
    return answer;
}