#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int add = 0;
    reverse(bin1.begin(), bin1.end());
    reverse(bin2.begin(), bin2.end());
    int ssize = bin1.size() > bin2.size() ? bin2.size() : bin1.size();
    int lsize = bin1.size() < bin2.size() ? bin2.size() : bin1.size();
    for (int i=0; i<ssize; i++){
        if(add == 0){
            if(bin1[i] == '1' && bin2[i] == '1'){
                add = 1;
                answer+='0';
            }
            else if(bin1[i] == '0' && bin2[i] == '0') answer+='0';
            else answer+='1';
        }
        else{
            if(bin1[i] == '1' && bin2[i] == '1'){
                add = 1;
                answer+='1';
            }
            else if(bin1[i] == '0' && bin2[i] == '0'){
                answer+='1';
                add = 0;
            }
            else {
                answer+='0';
                add = 1;
            }
        }
    }
    for (int i=ssize; i<lsize; i++){
        if(add == 0){
            if(bin1[i] == '1' || bin2[i] == '1'){
                add = 0;
                answer+='1';
            }
            else if(bin1[i] == '0' || bin2[i] == '0'){
                add = 0;
                answer+='0';
            }
        }
        else{
            if(bin1[i] == '1' || bin2[i] == '1'){
                add = 1;
                answer+='0';
            }
            else if(bin1[i] == '0' || bin2[i] == '0'){
                add = 0;
                answer+='1';
            }
        }
    }
    if(add==1) answer+='1';
    reverse(answer.begin(), answer.end());
    return answer;
}