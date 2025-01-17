#include <string>
#include <vector>
#include<algorithm>
#include <limits.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (vector<int> v: queries){
        int min_val = INT_MAX;
        for (int i = 0; i<arr.size(); i++){
            if (v[0] <= i && i <= v[1] && v[2] < arr[i]){
                min_val = min(min_val, arr[i]);
            }
        }
        if (min_val == INT_MAX ) min_val = -1;
        answer.push_back(min_val);
    }
    return answer;
}