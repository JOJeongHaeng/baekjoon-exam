#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    if(direction == "right"){
        vector<int> answer;
        answer.push_back(numbers.back());
        vector<int> tmp(numbers.begin(), numbers.end()-1);
        for(int i : tmp) answer.push_back(i);
        return answer;
    }
    else{
        vector<int> answer(numbers.begin()+1, numbers.end());
        answer.push_back(numbers[0]);
        return answer;
    }
}