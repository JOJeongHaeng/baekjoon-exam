#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(), mats.end(), greater<int>());
    for(int mat : mats){
        if(park.size() < mat || park[0].size() < mat) continue;
        for(int i=0; i<=park.size()-mat; i++){
            for(int j=0; j<=park[0].size()-mat; j++){
                int count = 0;
                for(int y=i; y<i+mat; y++){
                    for(int x=j; x<j+mat; x++){
                        if(park[y][x] != "-1") break;
                        else count++;
                    }
                }
                if(count == mat*mat) return mat;
            }
        }
    }
    return -1;
}