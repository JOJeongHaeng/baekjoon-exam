#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int maxnum = array[0];
    for(int i : array){
        maxnum = max(maxnum, i);
    }
    answer.push_back(maxnum);
    answer.push_back(find(array.begin(), array.end(), maxnum) - array.begin());
    return answer;
}