#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int max = 1;
    while (max < arr.size()) max*=2;
    while (arr.size()<max) arr.push_back(0);
    return arr;
}