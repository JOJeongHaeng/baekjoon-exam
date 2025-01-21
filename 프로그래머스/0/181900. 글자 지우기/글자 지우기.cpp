#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    int minus = 0;
    sort(indices.begin(), indices.end(), greater<>());
    for (int i : indices){
        my_string.erase(my_string.begin()+i);
    }
    return my_string;
}