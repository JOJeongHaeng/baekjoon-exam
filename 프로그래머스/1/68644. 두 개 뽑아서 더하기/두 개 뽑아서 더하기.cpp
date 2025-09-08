#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> setanswer;
    for(int i =0; i< numbers.size(); i++)
    {
        for(int j = 1; j < numbers.size(); j++)
        {
            if(i < j) setanswer.insert(numbers[i]+numbers[j]);
        }
    }
    for(int i : setanswer)
    {
        answer.push_back(i);
    }
    return answer;
}