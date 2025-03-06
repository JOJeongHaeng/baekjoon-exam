#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int idx_y;
    int idx_x;
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[0].size(); j++){
            if(park[i][j] == 'S') {
                idx_y = i; idx_x = j;
            }
        }
    }
    for(string route : routes){
        if(route[0] == 'N'){
            int check = 1;
            if(idx_y-(route[2]-'0') < 0) continue;
            for(int i=1; i<=route[2]-'0'; i++){
                if(park[idx_y-i][idx_x] == 'X') check = 0;
            }
            if(check == 1) idx_y-=(route[2]-'0');
        }
        else if(route[0] == 'S'){
            int check = 1;
            if(idx_y+(route[2]-'0') >= park.size()) continue;
            for(int i=1; i<=route[2]-'0'; i++){
                if(park[idx_y+i][idx_x] == 'X') check = 0;
            }
            if(check == 1) idx_y+=(route[2]-'0');
        }
        else if(route[0] == 'W'){
            int check = 1;
            if(idx_x-(route[2]-'0') < 0) continue;
            for(int i=1; i<=route[2]-'0'; i++){
                if(park[idx_y][idx_x-i] == 'X') check = 0;
            }
            if(check == 1) idx_x-=(route[2]-'0');
        }
        else if(route[0] == 'E'){            
            int check = 1;
            if(idx_x+(route[2]-'0') >= park[0].size()) continue;
            for(int i=1; i<=route[2]-'0'; i++){
                if(park[idx_y][idx_x+i] == 'X') check = 0;
            }
            if(check == 1) idx_x+=(route[2]-'0');
        }
    }
    answer.push_back(idx_y);
    answer.push_back(idx_x);
    return answer;
}