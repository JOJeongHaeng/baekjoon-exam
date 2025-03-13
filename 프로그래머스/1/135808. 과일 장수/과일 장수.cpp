#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int minus = score.size()%m;
    sort(score.begin(), score.end(), greater<>());
    for(int i=0; i<score.size()-minus; i+=m){
        answer+=score[i+m-1]*m;
    }
    return answer;
}