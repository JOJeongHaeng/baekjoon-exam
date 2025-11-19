#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> dfs(vector<vector<int>>& arr)
{
    int size = arr.size();
    map<int, int> result;
    vector<pair<int, int>> range = {{0, 0}, {0, size/2}, {size/2, 0}, {size/2, size/2}};
    
    if(size/2 == 1)
    {
        result[arr[0][0]]++;
        result[arr[0][1]]++;
        result[arr[1][0]]++;
        result[arr[1][1]]++;
        
        return result;
    }
    
    for(int i = 0; i<4; i++)
    {
        pair<int, int> now = range[i];
        
        vector<vector<int>> v(size/2, vector<int>(size/2, 0));
        
        map<int, int> count;
        for(int j = 0; j<size/2; j++)
        {
            for(int k = 0; k<size/2; k++)
            {
                int ny = j+now.first;
                int nx = k+now.second;
                v[j][k] = arr[ny][nx];
                
                count[arr[ny][nx]]++;
            }
        }
        if(count[0] == (size/2) * (size/2)) count[0] = 1;
        else if(count[1] == (size/2) * (size/2)) count[1] = 1;
        else count = dfs(v);
        
        result[0] += count[0];
        result[1] += count[1];
    }
    return result;
}

vector<int> solution(vector<vector<int>> arr) {
    map<int, int> result;
    result = dfs(arr);
    if(result[0] == 0) return {0, 1};
    else if(result[1] == 0) return {1, 0};
    return {result[0], result[1]};
}