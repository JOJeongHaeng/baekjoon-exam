#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int max1 = max(sides[0], sides[1]);
    int min1 = min(sides[0], sides[1]);
    
    for(int i=1; i<=max1; i++){
        if(i+min1>max1) answer++;
    }
    for(int i=max1+1; i<max1+min1; i++){
        answer++;
    }
    return answer;
}