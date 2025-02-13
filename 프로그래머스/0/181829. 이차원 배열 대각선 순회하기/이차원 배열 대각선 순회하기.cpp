#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    int col = board.size();
    int row = board[0].size();
    for (int i=0; i<col; i++){
        for (int j=0; j<row; j++){
            if (i+j <= k) answer+=board[i][j];
        }
    }
    return answer;
}