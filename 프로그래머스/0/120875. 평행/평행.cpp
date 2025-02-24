#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<vector<int>> check = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    for(vector<int> v : check){
        vector<int> nums = {0, 1, 2, 3};
        int i = v[0];
        int j = v[1];
        nums.erase(remove(nums.begin(), nums.end(), i), nums.end());
        nums.erase(remove(nums.begin(), nums.end(), j), nums.end());
        int k = nums[0];
        int l = nums[1];
        double inc1 = (double)(dots[i][1]-dots[j][1])/(double)(dots[i][0]-dots[j][0]);
        double inc2 = (double)(dots[k][1]-dots[l][1])/(double)(dots[k][0]-dots[l][0]);
        if (inc1 == inc2) answer = 1;
    }
    return answer;
}