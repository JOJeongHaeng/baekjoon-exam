#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    vector<int> mul;
    int tmp=1;
    for(int i=0; i < numbers.size(); i++){
        for(int j = tmp; j < numbers.size(); j++){
                mul.push_back(numbers[i]*numbers[j]);
        }
        tmp++;
    }
    int answer = mul[0];
    for(int i : mul){
        answer = max(answer, i);
    }
    return answer;
}