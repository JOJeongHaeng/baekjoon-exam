#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    set<int> painting;
    for(int off : section){
        if(painting.find(off) == painting.end()){
            answer++;
            for(int i=off; i<off+m; i++){
                painting.insert(i);
            }
        }
    }
    return answer;
}