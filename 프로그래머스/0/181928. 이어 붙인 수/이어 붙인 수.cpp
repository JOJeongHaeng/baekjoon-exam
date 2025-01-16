#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string str1 = ""; 
    string str2 = "";
    for (int i : num_list){
        if (i%2 ==1){
            str1 += to_string(i);
        }
        else{
            str2 += to_string(i);
        }
    }
    int answer = stoi(str1)+stoi(str2);
    return answer;
}