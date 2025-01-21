#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;    
    if (n==1){
        return vector<int>(num_list.begin(), num_list.begin()+slicer[1]+1);
    }
    else if (n ==2){
        return vector<int>(num_list.begin()+slicer[0], num_list.end());
    }
    else if (n==3){
        return vector<int>(num_list.begin()+slicer[0], num_list.begin()+slicer[1]+1);
    }
    else{
        answer = vector<int>(num_list.begin()+slicer[0], num_list.begin()+slicer[1]+1);
        vector<int> v;
        for (int i = 0; i<answer.size(); i+=slicer[2]) v.push_back(answer[i]);
        return v;
    }
}