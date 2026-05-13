#include <string>
#include <vector>
#include <map>

using namespace std;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solution(vector<int> arrows) {
    map<pair<int, int>, bool> node_visited;
    map<pair<pair<int, int>, pair<int, int>>, bool> edge_visited;
    
    int answer = 0;
    int x = 0, y = 0;
    node_visited[{y, x}] = true;
    for(int i = 0; i<arrows.size(); i++)
    {
        int dir = arrows[i];
        for(int j = 0; j<2; j++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(node_visited[{ny, nx}] && !edge_visited[{{ny, nx}, {y, x}}])
            {
                edge_visited[{{ny, nx}, {y, x}}] = true;
                edge_visited[{{y, x}, {ny, nx}}] = true;
                
                answer++;
                x = nx;
                y = ny;
                continue;
            }
            node_visited[{ny, nx}] = true;
            edge_visited[{{ny, nx}, {y, x}}] = true;
            edge_visited[{{y, x}, {ny, nx}}] = true;
            x = nx;
            y = ny;
        }
    }
    return answer;
}