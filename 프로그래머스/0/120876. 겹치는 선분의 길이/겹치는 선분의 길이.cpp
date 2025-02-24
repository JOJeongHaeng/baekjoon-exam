#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<vector<int>> lines) {
    set<int> s;
    for(int i=lines[0][0]; i<lines[0][1]; i++){
        for(int j=lines[1][0]; j<lines[1][1]; j++) if(i==j) s.insert(i);
    }
    
    for(int i=lines[0][0]; i<lines[0][1]; i++){
        for(int j=lines[2][0]; j<lines[2][1]; j++) if(i==j) s.insert(i);
    }
    
    for(int i=lines[1][0]; i<lines[1][1]; i++){
        for(int j=lines[2][0]; j<lines[2][1]; j++) if(i==j) s.insert(i);
    }
    return s.size();
}