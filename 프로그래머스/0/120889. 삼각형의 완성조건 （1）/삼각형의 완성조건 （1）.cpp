#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int tmp = sides[0];
    int sum = 0;
    for (int i=0; i<sides.size(); i++){
        sum += sides[i];
        if(sides[i] > tmp) tmp = sides[i];
    }
    if(sum-tmp > tmp) return 1;
    else return 2;
}