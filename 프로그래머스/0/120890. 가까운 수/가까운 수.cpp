#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = array[0];
    int tmp = abs(n-array[0]);
    for(int i=0; i<array.size(); i++){
        if(abs(n-array[i]) < tmp) {
            tmp=abs(n-array[i]);
            answer=array[i];
        }
        else if(abs(n-array[i]) == tmp) answer = array[i] < answer ? array[i]:answer;
    }
    return answer;
}