#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int col = 0; int row = 0;
    string direction = "right";
    for(int i=1; i<=n*n; i++){
        if(direction == "right"){
            if(row == n-1 || answer[col][row+1] != 0) {
                answer[col][row] = i;
                col++;
                direction = "bottom";
            }
            else {
                answer[col][row] = i;
                row++;
            }
        }
        else if(direction == "bottom"){
            if(col == n-1 || answer[col+1][row] != 0) {
                answer[col][row] = i;
                row--;
                direction = "left";
            }
            else {
                answer[col][row] = i;
                col++;
            }
        }
        else if(direction == "left"){
            if(row == 0 || answer[col][row-1] != 0) {
                answer[col][row] = i;
                col--;
                direction = "top";
            }
            else {
                answer[col][row] = i;
                row--;
            }
        }
        else if(direction == "top"){
            if(col == 0 || answer[col-1][row] != 0) {
                answer[col][row] = i;
                row++;
                direction = "right";
            }
            else {
                answer[col][row] = i;
                col--;
            }
        }
    }
    return answer;
}