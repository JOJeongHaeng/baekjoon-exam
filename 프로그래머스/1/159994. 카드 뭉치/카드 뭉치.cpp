#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1=0; int idx2=0;
    for(string str : goal){
        bool check = false;
        if(idx1 < cards1.size()){
            if(cards1[idx1] == str){
                idx1++;
                check = true;
            }
        }
        if(idx2 < cards2.size()){
            if(cards2[idx2] == str){
                idx2++;
                check = true;
            }
        }
        if(check == false) return "No";
    }
    return "Yes";
}