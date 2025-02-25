#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<int>> tmp = board;
    vector<vector<int>> test = {{1, 0}, {-1, 0}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}, {0, 1}, {0, -1}};
    for(int y=0; y<board.size(); y++){
        for(int x=0; x<board.size(); x++){
            if(board[y][x]==1){
                for(vector<int> t : test){
                    if(0 <= y+t[0] && y+t[0] < board.size()){
                        if(0 <= x+t[1] && x+t[1] < board.size()){
                            tmp[y+t[0]][x+t[1]]++;
                        }
                    }
                }
            }
        }
    }
    for(int y=0; y<board.size(); y++){
        for(int x=0; x<board.size(); x++){
            if(tmp[y][x] == 0) answer++;
        }
    }
    return answer;
}