#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int size = num_list.size();
    num_list.push_back(num_list.back() > num_list.at(size-2) ? num_list.back() - num_list.at(size-2) : num_list.back()*2);
    return num_list;
}