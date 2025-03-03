#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = n*12000;
    if(n/10 != 0) k-=n/10;
    answer+=k*2000;
    return answer;
}