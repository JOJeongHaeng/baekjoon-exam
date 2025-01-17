#include <string>
#include <vector>

using namespace std;

bool solution(bool x1, bool x2, bool x3, bool x4) {
    bool answer = true;
    if (x1 == false && x2 == false){
        answer = false;
    }
    else if (x3 == false && x4 == false){
        answer = false;
    }
    return answer;
}