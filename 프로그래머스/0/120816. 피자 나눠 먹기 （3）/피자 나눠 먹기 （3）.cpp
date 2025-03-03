#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 1;
    for(int i=slice; i<n; i+=slice) answer++;
    return answer;
}