#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    for(int i=0; i<M-1; i++) answer+=1;
    for(int j=0; j<(N-1)*M; j++) answer+=1;
    return answer;
}