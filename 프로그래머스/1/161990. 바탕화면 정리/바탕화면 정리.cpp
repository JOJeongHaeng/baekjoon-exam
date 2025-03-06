#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    for(int y=0; y<wallpaper.size(); y++){
        for(int x=0; x<wallpaper[0].size(); x++){
            if(wallpaper[y][x] == '#') {
                answer.push_back(y);
                break;
            }
        }
        if(answer.size() == 1) break;
    }
    for(int x=0; x<wallpaper[0].size(); x++){
        for(int y=0; y<wallpaper.size(); y++){
            if(wallpaper[y][x] == '#') {
                answer.push_back(x);
                break;
            }
        }
        if(answer.size() == 2) break;
    }
    for(int y=wallpaper.size()-1; y>=0; y--){
        for(int x=0; x<wallpaper[0].size(); x++){
            if(wallpaper[y][x] == '#') {
                answer.push_back(++y);
                break;
            }
        }
        if(answer.size() == 3) break;
    }
    for(int x=wallpaper[0].size()-1; x>=0; x--){
        for(int y=0; y<wallpaper.size(); y++){
            if(wallpaper[y][x] == '#') {
                answer.push_back(++x);
                break;
            }
        }
        if(answer.size() == 4) break;
    }
    return answer;
}