#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    vector<int> list;
    int n = 1;
    while(list.size()<3){
        for (int i=0; i<rank.size(); i++){
            if(rank[i]==n && attendance[i]==true){
                list.push_back(i);
                n++;
            }
            else if(rank[i]==n && attendance[i]==false){
                n++;
            }
        }
    } 
    return 10000*list[0]+100*list[1]+list[2];
}