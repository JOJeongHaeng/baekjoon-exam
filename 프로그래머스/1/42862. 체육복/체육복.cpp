#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    vector<int> vec(n, 1);
    for(int l : lost) vec[l-1] = 0;
    for(int r : reserve) vec[r-1]++;
    for(int l : lost)
    {
        if(vec[l-1] == 0)
        {
            if(l-2 >= 0 && vec[l-2] == 2) vec[l-2]--, vec[l-1]++;
            else if(l < n && vec[l] == 2) vec[l]--, vec[l-1]++;
        }
    }
    for(int i : vec) if(i!=0) answer++;
    return answer;
}