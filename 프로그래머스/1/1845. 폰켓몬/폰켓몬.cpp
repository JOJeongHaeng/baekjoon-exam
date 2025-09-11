#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int, bool> m;
    for(int num : nums) m[num] = 1;
    if(m.size() >= nums.size()/2) return nums.size()/2;
    else return m.size();
}