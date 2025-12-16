#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> maps;
    for(int i = 0; i<rows; i++)
    {
        vector<int> tmp;
        for(int j = 1; j<=columns; j++)
        {
            tmp.push_back((i*columns)+j);
        }
        maps.push_back(tmp);
    }
    
    for(auto q : queries)
    {
        int y = q[0]-1;
        int x = q[1]-1;
        int last = maps[y][x];
        int tmp;
        
        char dir = 'R';
        
        int min = last;
        
        while(dir != 'E')
        {
            switch(dir)
            {
                case 'R':
                    if(y == q[0]-1 && x == q[3]-1)
                    {
                        dir = 'D';
                    }
                    else
                    {
                        tmp = maps[y][x+1];
                        maps[y][x+1] = last;
                        last = tmp;
                        if(last < min) min = last;
                        x++;
                    }
                    break;
                case 'D':
                    if(y == q[2]-1 && x == q[3]-1)
                    {
                        dir = 'L';
                    }
                    else
                    {
                        tmp = maps[y+1][x];
                        maps[y+1][x] = last;
                        last = tmp;
                        if(last < min) min = last;
                        y++;
                    }
                    break;
                case 'L':
                    if(y == q[2]-1 && x == q[1]-1)
                    {
                        dir = 'U';
                    }
                    else
                    {
                        tmp = maps[y][x-1];
                        maps[y][x-1] = last;
                        last = tmp;
                        if(last < min) min = last;
                        x--;
                    }
                    break;
                case 'U':
                    if(y == q[0]-1 && x == q[1]-1)
                    {
                        dir = 'E';
                    }
                    else
                    {
                        tmp = maps[y-1][x];
                        maps[y-1][x] = last;
                        last = tmp;
                        if(last < min) min = last;
                        y--;
                    }
                    break;
            }
        }
        answer.push_back(min);
    }
    return answer;
}