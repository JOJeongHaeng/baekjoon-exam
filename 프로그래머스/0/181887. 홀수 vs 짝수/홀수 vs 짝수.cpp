#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum_o = 0;
    int sum_e = 0;
    for (int i=0; i<num_list.size(); i++){
        if (i%2==0){
            sum_o+=num_list[i];
        }
        else{
            sum_e+=num_list[i];
        }
    }
    if (sum_o>=sum_e) return sum_o;
    else return sum_e;
}