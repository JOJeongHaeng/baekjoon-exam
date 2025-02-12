#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    for(int col=0; col<n; col++){
        vector<int> tmp;
        for(int row=0; row<n; row++){
            if(col==row) tmp.push_back(1);
            else tmp.push_back(0);
            }
        answer.push_back(tmp);
    }
    return answer;
}