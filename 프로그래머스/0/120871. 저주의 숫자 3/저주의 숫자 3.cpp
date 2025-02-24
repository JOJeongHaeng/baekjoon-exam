#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> nums;
    for(int i=1; i<200; i++){
        if(i%3 == 0) continue;
        else if(to_string(i).find("3") != string::npos) continue;
        else nums.push_back(i);
    }
    return nums[n-1];
}