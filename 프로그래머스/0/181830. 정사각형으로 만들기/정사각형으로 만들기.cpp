#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int col = arr.size();
    int row = arr[0].size();
    if (col > row){
        for (int j=0; j<col-row; j++){
            for (int i=0; i<col; i++) arr[i].push_back(0);
        }
    }
    else if (col < row){
        vector<int> tmp;
        for(int i=0; i<row; i++){
            tmp.push_back(0);
        }
        for(int i=0; i<row-col; i++){
            arr.push_back(tmp);
        }
    }
    return arr;
}