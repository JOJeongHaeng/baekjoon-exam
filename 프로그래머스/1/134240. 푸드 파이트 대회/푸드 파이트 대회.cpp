#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i=1; i<food.size(); i++){
        while(food[i]/2 != 0){
            answer+=to_string(i);
            food[i]-=2;
        }
    }
    string r_answer = answer;
    reverse(r_answer.begin(), r_answer.end());
    answer+='0'+r_answer;
    return answer;
}