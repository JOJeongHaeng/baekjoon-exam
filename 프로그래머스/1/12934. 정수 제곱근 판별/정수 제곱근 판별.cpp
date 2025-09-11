#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = sqrt(n);
    return answer * answer == n ? pow(++answer, 2) : -1;
}