#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int tmp;
    a > b ? tmp = a, a = b, b = tmp : 0;
    for(int i = a; i<=b; i++) answer+=i;
    return answer;
}