#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    int dif;
    string zeros = "";
    dif = a.size() - b.size();
    dif = dif < 0 ? dif*-1 : dif;
    for (int i = 0; i < dif; i++) zeros+="0";
    if (a.size() > b.size()) b = zeros+b;
    else if (a.size() < b.size()) a = zeros+a;
    int a1; int b1; int carry = 0;
    for (int i = a.size() -1; i>=0; i--){
        a1 = a[i] - '0';
        b1 = b[i] - '0';
        if (a1+b1+carry >= 10){
            answer+=to_string((a1+b1+carry)%10);
            carry = 1;
        }
        else{
            answer+=to_string((a1+b1+carry)%10);
            carry = 0;
        }
    }
    if (carry) answer+="1";
    reverse(answer.begin(), answer.end());
    return answer;
}