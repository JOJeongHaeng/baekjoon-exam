#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    for(int i : delete_list){
        vector<int>::iterator idx = find(arr.begin(), arr.end(), i);
        if(idx != arr.end()){
            arr.erase(idx);
        }
    }
    return arr;
}