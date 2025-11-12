#include <string>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int solution(int x, int y, int n) {
    queue<pair<int, int>> q;
    q.push({y, 0});
    
    while(!q.empty())
    {
        int pos = q.front().first;
        int count = q.front().second;
        q.pop();
        
        if(pos == x) return count;
        if(pos-n >= x) q.push({pos-n, count+1});
        if(pos%2 == 0) q.push({pos/2, count+1});
        if(pos%3 == 0) q.push({pos/3, count+1});
    }
    return -1;
}