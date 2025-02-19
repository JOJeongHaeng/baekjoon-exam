#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    while(chicken>0){
        chicken-=10;
        if(chicken >= 0){
            answer++;
            chicken++;
        }
    }
    return answer;
}