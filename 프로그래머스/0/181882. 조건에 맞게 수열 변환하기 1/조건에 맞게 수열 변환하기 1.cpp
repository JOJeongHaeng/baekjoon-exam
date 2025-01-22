#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    for (int &i : arr){
        if (i<50 && i%2==1) i*=2;
        else if (50 <= i && i%2==0) i/=2;
    }
    return arr;
}