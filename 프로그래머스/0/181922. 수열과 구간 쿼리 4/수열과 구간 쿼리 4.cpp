#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (vector q: queries){
        for (int i=0; i < arr.size(); i++){
            if (q[0] <= i && i <= q[1] && i%q[2] == 0){
                arr[i]+=1;
            }
        }
    }
    return arr;
}