#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> front = vector<int>(num_list.begin()+n, num_list.end());
    vector<int> back = vector<int>(num_list.begin(), num_list.begin()+n);
    for (int i: back) front.push_back(i);
    return front;
}