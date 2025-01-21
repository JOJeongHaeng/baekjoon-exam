#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = -1;
    for (int n =0; n < num_list.size(); n++){
        if (num_list[n] < 0) return n;
    }
    return answer;
}