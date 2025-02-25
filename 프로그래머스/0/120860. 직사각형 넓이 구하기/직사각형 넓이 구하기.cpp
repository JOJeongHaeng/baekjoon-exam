#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int i;
    vector<int> index = {1, 2, 3};
    if(dots[0][1] == dots[1][1]) i = 1;
    else if(dots[0][1] == dots[2][1]) i = 2;
    else if(dots[0][1] == dots[3][1]) i = 3;
    index.erase(index.begin() + i-1);
    answer = abs(dots[0][0] - dots[i][0]) * abs(dots[0][1] - dots[index[1]][1]);
    return answer;
}