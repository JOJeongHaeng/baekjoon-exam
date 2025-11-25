#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int seconds = 1;
    int total_weight = 0;
    int on_bridge = 0;
    
    
    queue<pair<int, int>> q;
    for(int i = 0; i<truck_weights.size(); i++)
    {
        if(on_bridge == bridge_length || total_weight + truck_weights[i] > weight)
        {
            pair<int, int> truck = q.front();
            q.pop();
            
            total_weight -= truck.first;
            on_bridge--;
            seconds = seconds > truck.second + bridge_length ? seconds : truck.second + bridge_length;
            i--;
        }
        else
        {
            q.push({truck_weights[i], seconds});
            on_bridge++;
            total_weight += truck_weights[i];
            
            seconds++;
        }
    }
    while(!q.empty())
    {
        pair<int, int> truck = q.front();
        q.pop();
        seconds = truck.second + bridge_length;
    }
    
    return seconds;
}