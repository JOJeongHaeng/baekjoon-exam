#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    for (int i : num_list){
        while(i!=1){
            i/=2;
            answer++;
        }
    }
    return answer;
}