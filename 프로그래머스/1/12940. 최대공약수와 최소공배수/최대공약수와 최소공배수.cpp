#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max;
    for(int i = 1; i<=n; i++)
    {
        if(n%i == 0 && m%i == 0) max = i;
    }
    int x = n;
    int y = m;
    while(x != y) x<y ? x+=n : y+=m;
    answer = { max, x };
    return answer;
}