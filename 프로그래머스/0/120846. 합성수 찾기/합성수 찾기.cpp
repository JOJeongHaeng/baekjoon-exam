#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=4; i<=n; i++){
        vector<int> tmp;
        for(int j=1; j<=i; j++){
            if(i%j == 0) tmp.push_back(j);
        }
        if(tmp.size()>2) answer++;
    }
    return answer;
}