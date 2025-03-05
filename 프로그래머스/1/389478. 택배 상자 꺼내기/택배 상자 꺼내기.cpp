#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int count = 1;
    vector<vector<int>> boxes;
    vector<int> tmp;
    for(int i=1; i<=n; i++){
        if(i%w == 0){
            tmp.push_back(i);
            boxes.push_back(tmp);
            tmp = {};
        }
        else tmp.push_back(i);
    }
    if(!tmp.empty()) {
        while(tmp.size() != w) tmp.push_back(0);
        boxes.push_back(tmp);
    }
    
    for(int i=1; i<boxes.size(); i+=2){
        reverse(boxes[i].begin(), boxes[i].end());
    }
    
    int idx_y;
    for(int i=0; i<boxes.size(); i++){
        if(find(boxes[i].begin(), boxes[i].end(), num) != boxes[i].end()) idx_y = i;
    }
    
    int idx_x; 
    for(int i=0; i<w; i++){
        if(boxes[idx_y][i] == num) idx_x = i;
    }
    
    if(boxes.back()[idx_x] != 0) return boxes.size()-idx_y;
    else return boxes.size()-idx_y-1;
}