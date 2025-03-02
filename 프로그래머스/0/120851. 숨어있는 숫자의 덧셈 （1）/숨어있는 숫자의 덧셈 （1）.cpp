#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string) {
    vector<char> nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int answer = 0;
    for(char c : my_string){
        if(find(nums.begin(), nums.end(), c) != nums.end()) answer+= c-'0';
    }
    return answer;
}