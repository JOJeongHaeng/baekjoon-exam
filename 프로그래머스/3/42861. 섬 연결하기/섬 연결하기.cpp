#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<int> us;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[2] < v2[2];
         });
    
    us.insert(costs[0][0]);
    us.insert(costs[0][1]);
    answer += costs[0][2];
    
     while(us.size() < n) {
        for(int i = 1; i < costs.size(); i++) {
            if (us.find(costs[i][0]) != us.end()
                && us.find(costs[i][1]) != us.end()) continue;
            if (us.find(costs[i][0]) != us.end()
                || us.find(costs[i][1]) != us.end()) {
                us.insert(costs[i][0]);
                us.insert(costs[i][1]);
                answer += costs[i][2];
                costs.erase(costs.begin() + i);
                break;
            }
        }
    }
    
    return answer;
}