#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> three;
    while(n > 0)
    {
        three.push_back(n%3);
        n /= 3;
    }
    int count = 0;
    do
    {
        answer += pow(3, count)*(three.back());
        three.pop_back();
        count+=1;
    }
    while(three.size() != 0);
    return answer;
}