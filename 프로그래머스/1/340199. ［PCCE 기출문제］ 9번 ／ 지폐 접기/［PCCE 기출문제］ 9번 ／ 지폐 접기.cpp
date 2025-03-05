#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int tmp;
    int w_max = max(wallet[0], wallet[1]);
    int w_min = min(wallet[0], wallet[1]);
    int b_max = max(bill[0], bill[1]);
    int b_min = min(bill[0], bill[1]);
    while(w_max < b_max || w_min < b_min){
        answer++;
        b_max/=2;
        if(b_max < b_min){
            tmp = b_max;
            b_max = b_min;
            b_min = tmp;
        }
    }
    return answer;
}