#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int start = 0;
    int end = distance;
    sort(rocks.begin(), rocks.end());
    
    while(start <= end)
    {
        int cnt = 0;
        int prev = 0;
        int mid = (start + end) / 2;
        for(int i = 0; i<rocks.size(); i++)
        {
            if(rocks[i] - prev < mid) cnt++;
            else prev = rocks[i];
        }
        if(distance - prev < mid) cnt++;

        if(cnt <= n)
        {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return answer;
}