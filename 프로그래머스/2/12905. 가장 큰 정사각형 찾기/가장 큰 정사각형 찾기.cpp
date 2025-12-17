#include <iostream>
#include<vector>
using namespace std;

int minF(const vector<vector<int>>& board, pair<int, int> p)
{
    int y = p.first;
    int x = p.second;
    int c_i[3] = {0, -1};
    int c_j[3] = {-1, 0};
    int min = board[y-1][x-1];
    for(int i = 0; i<2; i++)
    {
        if(board[y+c_i[i]][x+c_j[i]] < min) min = board[y+c_i[i]][x+c_j[i]];
    }
    
    return min;
}

int solution(vector<vector<int>> board)
{
    int max = board[board.size()-1][board[0].size()-1];
    for(int i = 1; i<board.size(); i++)
    {
        for(int j = 1; j<board[0].size(); j++)
        {
            if(board[i][j] == 1)
            {
                int min = minF(board, {i, j}) + 1;
                board[i][j] = min;
                if(max < min) max = min;
            }
        }
    }
    return max*max;
}