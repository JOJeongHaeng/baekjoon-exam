#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i*i<=n; i++) n%i == 0 ? i*i != n ? answer+=i + n/i : answer+=i : 0;
    return answer;
}