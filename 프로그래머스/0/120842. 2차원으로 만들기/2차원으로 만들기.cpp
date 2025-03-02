#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    vector<int> tmp;
    for(int i=0; i<n; i++) tmp.push_back(num_list[i]);
    answer.push_back(tmp);
    tmp = {};
    for(int i=n; i<num_list.size(); i+=n){
        for(int j=i; j<i+n; j++) tmp.push_back(num_list[j]);
        answer.push_back(tmp);
        tmp = {};
    }
    return answer;
}