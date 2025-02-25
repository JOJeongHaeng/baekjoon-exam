#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = numbers[0] * numbers[1];
    for(int i : numbers){
        for(int j : numbers){
            if(i != j){
                if(i*j > answer) answer = i*j;
            }
        }
    }
    return answer;
}