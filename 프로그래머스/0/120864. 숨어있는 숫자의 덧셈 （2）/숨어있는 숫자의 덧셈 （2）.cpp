#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string tmp;
    vector<int> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(char ch : my_string){
        if(find(nums.begin(), nums.end(), ch) != nums.end()){
            tmp+=ch;
        }
        else{
            if(tmp.size() != 0) {
                answer+= stoi(tmp);
                tmp = "";
            }
        }
    }
    if(tmp.size() != 0) answer+= stoi(tmp);
    return answer;
}